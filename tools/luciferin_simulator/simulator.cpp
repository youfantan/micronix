#pragma once

#include <iostream>
#include <cstdint>
#include <Windows.h>
#include <luciferin/color.h>
#include <luciferin/graphics2d.h>
#include <faces.h>

#define NOMINMAX

namespace micronix::luciferin
{
    constexpr static u32 SimulatorWidth = 1280;
    constexpr static u32 SimulatorHeight = 640;

    struct SimulatorContext {
        constexpr static u32 Width = SimulatorWidth;
        constexpr static u32 Height = SimulatorHeight;
        using ColorFormat = ColorFormatRGB24;
    };

    struct SimulatorAdapter {
        using Context = SimulatorContext;

    private:
        constexpr static wchar_t WindowClassName[] = L"LuciferinSimulatorWindow";

        inline static HWND window_ = nullptr;
        inline static HDC window_dc_ = nullptr;
        inline static HDC framebuffer_dc_ = nullptr;
        inline static HBITMAP framebuffer_bitmap_ = nullptr;
        inline static HGDIOBJ previous_bitmap_ = nullptr;
        inline static void* framebuffer_bits_ = nullptr;
        inline static bool window_open_ = false;

    public:
        static void initialize() {
            if (available()) {
                return;
            }

            destroy();

            WNDCLASSEXW windowClass{};
            windowClass.cbSize = sizeof(windowClass);
            windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
            windowClass.lpfnWndProc = &WindowProcedure;
            windowClass.hInstance = GetModuleHandleW(nullptr);
            windowClass.hCursor = LoadCursorW(nullptr, MAKEINTRESOURCEW(32512));
            windowClass.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
            windowClass.lpszClassName = WindowClassName;

            if (!RegisterClassExW(&windowClass) &&
                GetLastError() != ERROR_CLASS_ALREADY_EXISTS) {
                fallback("SimulatorAdapter: Failed to register the window class");
                return;
            }

            RECT windowRect{ 0, 0, Context::Width, Context::Height };
            if (!AdjustWindowRect(&windowRect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE)) {
                fallback("SimulatorAdapter: Failed to calculate the window size");
                return;
            }

            window_ = CreateWindowExW(
                0,
                WindowClassName,
                L"Luciferin Simulator",
                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                windowRect.right - windowRect.left,
                windowRect.bottom - windowRect.top,
                nullptr,
                nullptr,
                GetModuleHandleW(nullptr),
                nullptr);
            if (!window_) {
                fallback("SimulatorAdapter: Failed to create the window");
                destroy();
                return;
            }

            window_dc_ = GetDC(window_);
            framebuffer_dc_ = CreateCompatibleDC(window_dc_);
            if (!window_dc_ || !framebuffer_dc_) {
                fallback("SimulatorAdapter: Failed to create a device context");
                destroy();
                return;
            }

            BITMAPINFO bmp_info{};
            bmp_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmp_info.bmiHeader.biWidth = static_cast<LONG>(Context::Width);
            bmp_info.bmiHeader.biHeight = -static_cast<LONG>(Context::Height);
            bmp_info.bmiHeader.biPlanes = 1;
            bmp_info.bmiHeader.biBitCount = 32;
            bmp_info.bmiHeader.biCompression = BI_RGB;

            framebuffer_bitmap_ = CreateDIBSection(
                window_dc_,
                &bmp_info,
                DIB_RGB_COLORS,
                &framebuffer_bits_,
                nullptr,
                0);
            if (!framebuffer_bitmap_ || !framebuffer_bits_) {
                fallback("SimulatorAdapter: Failed to create the framebuffer bitmap");
                destroy();
                return;
            }

            previous_bitmap_ = SelectObject(framebuffer_dc_, framebuffer_bitmap_);
            window_open_ = true;

            ShowWindow(window_, SW_SHOWNORMAL);
            UpdateWindow(window_);
        }

        static void destroy() {
            window_open_ = false;

            if (framebuffer_dc_) {
                if (previous_bitmap_) {
                    SelectObject(framebuffer_dc_, previous_bitmap_);
                    previous_bitmap_ = nullptr;
                }
                DeleteDC(framebuffer_dc_);
                framebuffer_dc_ = nullptr;
            }

            if (framebuffer_bitmap_) {
                DeleteObject(framebuffer_bitmap_);
                framebuffer_bitmap_ = nullptr;
            }
            framebuffer_bits_ = nullptr;

            if (window_dc_ && window_) {
                ReleaseDC(window_, window_dc_);
            }
            window_dc_ = nullptr;

            if (window_) {
                if (IsWindow(window_)) {
                    DestroyWindow(window_);
                }
                window_ = nullptr;
            }
        }

        static void present(const void* framebuffer) {
            if (!available() || !framebuffer || !framebuffer_bits_) {
                return;
            }

            auto* destination = static_cast<u8*>(framebuffer_bits_);
            constexpr u32 pixelCount = Context::Width * Context::Height;
            for (u32 pixel = 0; pixel < pixelCount; ++pixel) {
                const u8* source_pixel = static_cast<const u8*>(framebuffer) + pixel * 3;
                u8* dest_pixel = destination + pixel * 4;
                dest_pixel[0] = source_pixel[2];
                dest_pixel[1] = source_pixel[1];
                dest_pixel[2] = source_pixel[0];
                dest_pixel[3] = 255;
            }
            GdiFlush();
            InvalidateRect(window_, nullptr, FALSE);
            UpdateWindow(window_);

            MSG message{};
            while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE)) {
                if (message.message == WM_QUIT) {
                    window_open_ = false;
                    break;
                }
                TranslateMessage(&message);
                DispatchMessageW(&message);
            }
        }

        static bool available() {
            return window_open_ && window_ && IsWindow(window_);
        }

        static void fallback(const char* str) {
            std::cout << str << std::endl;
        }

    private:
        static LRESULT CALLBACK WindowProcedure(
            HWND window,
            UINT message,
            WPARAM wParam,
            LPARAM lParam) {
            switch (message) {
                case WM_PAINT: {
                    PAINTSTRUCT paint{};
                    HDC paintDc = BeginPaint(window, &paint);
                    if (framebuffer_dc_) {
                        BitBlt(
                            paintDc,
                            0,
                            0,
                            Context::Width,
                            Context::Height,
                            framebuffer_dc_,
                            0,
                            0,
                            SRCCOPY);
                    }
                    EndPaint(window, &paint);
                    return 0;
                }
                case WM_ERASEBKGND:
                    return 1;
                case WM_CLOSE:
                    DestroyWindow(window);
                    return 0;
                case WM_DESTROY:
                    window_open_ = false;
                    PostQuitMessage(0);
                    return 0;
                case WM_KEYDOWN:
                    if (wParam == VK_ESCAPE) {
                        DestroyWindow(window);
                    }
                    return 0;
                default:
                    return DefWindowProcW(window, message, wParam, lParam);
            }
        }
    };
}

using adapter = micronix::luciferin::SimulatorAdapter;
using context = adapter::Context;
using color = context::ColorFormat;
using graphics2d = micronix::luciferin::graphics2d<adapter>;

uint8_t fb[graphics2d::get_framebuffer_size()];

int main() {

    graphics2d graphics(fb);
    while (adapter::available()) {
        for (u32 y = 0; y < context::Height; ++y)
            for (u32 x = 0; x < context::Width; ++x)
                graphics.draw_pixel(x, y, color(255, 0, 0));
        graphics.present();
    }
    return 0;
}