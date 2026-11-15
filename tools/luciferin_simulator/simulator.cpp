#include <iostream>
#include <cstdint>
#include <algorithm>
#include <exception>
#include <string_view>
#include <Windows.h>
#include <subsystem/luciferin/color.h>
#include <subsystem/luciferin/graphics2d.h>
#include "mock/platform.h"

namespace micronix::luciferin
{
    constexpr static u32 SimulatorWidth = 160;
    constexpr static u32 SimulatorHeight = 128;

    struct simulator_context {
        constexpr static u32 Width = SimulatorWidth;
        constexpr static u32 Height = SimulatorHeight;
        using color_format = color_format_rgb24;
    };

    struct simulator_adapter {
        using context = simulator_context;

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
                std::cerr << "SimulatorAdapter: Failed to register the window class" << std::endl;
                return;
            }

            RECT windowRect{ 0, 0, context::Width, context::Height };
            if (!AdjustWindowRect(&windowRect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE)) {
                std::cerr << "SimulatorAdapter: Failed to calculate the window size" << std::endl;
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
                std::cerr << "SimulatorAdapter: Failed to create the window" << std::endl;
                destroy();
                return;
            }

            window_dc_ = GetDC(window_);
            framebuffer_dc_ = CreateCompatibleDC(window_dc_);
            if (!window_dc_ || !framebuffer_dc_) {
                std::cerr << "SimulatorAdapter: Failed to create a device context" << std::endl;
                destroy();
                return;
            }

            BITMAPINFO bmp_info{};
            bmp_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmp_info.bmiHeader.biWidth = static_cast<LONG>(context::Width);
            bmp_info.bmiHeader.biHeight = -static_cast<LONG>(context::Height);
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
                std::cerr << "SimulatorAdapter: Failed to create the framebuffer bitmap" << std::endl;
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
            constexpr u32 pixelCount = context::Width * context::Height;
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
                            context::Width,
                            context::Height,
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

using adapter = micronix::luciferin::simulator_adapter;
using context = adapter::context;
using color = context::color_format;
using graphics2d = micronix::luciferin::graphics2d<adapter>;

uint8_t fb[graphics2d::get_framebuffer_size()];

int main(int argc, char** argv) {
    bool smoke_test = false;
    const char* image_path = MICRONIX_ROFS_IMAGE_PATH;
    for (int i = 1; i < argc; ++i) {
        if (std::string_view(argv[i]) == "--image" && i + 1 < argc) {
            image_path = argv[++i];
        } else {
            std::cerr << "Usage: " << argv[0] << " [--image rofs.image.bin] [--smoke-test]\n";
            return 1;
        }
    }

    micronix::simulator::load_rofs_image(image_path);
    auto font24 = micronix::luciferin::find_font("Font_Roboto_24px");
    auto font12 = micronix::luciferin::find_font("Font_Roboto_12px");
    if (!font24 || !font12) {
        std::cerr << "simulator: required Roboto fonts not found in ROFS" << std::endl;
        return 1;
    }

    graphics2d graphics(fb, ROFS_ImageBase);
    if (!adapter::available()) return 1;

    for (u32 y = 0; y < context::Height; ++y) {
        for (u32 x = 0; x < context::Width; ++x) {
            graphics.draw_pixel(x, y, color(255, 255, 255));
        }
    }

    graphics.draw_string(10, 40, font24.get(), micronix::utf32_string_literal(U"micronix::luciferin"));
    graphics.draw_string(10, 80, font24.get(), micronix::utf32_string_literal(U"Render-subsystem-demo"));
    graphics.draw_string(10, 120, font12.get(), micronix::utf32_string_literal(U"ROFS:Font_Roboto_12px"));
    graphics.draw_string(10, 145, font12.get(), micronix::utf32_string_literal(U"0123456789!@#$%&*()"));
    graphics.present();

    if (smoke_test) {
        const auto row_has_pixels = [](u32 begin, u32 end) {
            return std::any_of(fb + begin * context::Width * 3,
                fb + end * context::Width * 3, [](u8 value) { return value != 0; });
        };
        if (!row_has_pixels(0, 90) || !row_has_pixels(90, 150)) {
            std::cerr << "simulator: font rendering produced no pixels" << std::endl;
            return 1;
        }
        std::cout << "ROFS loaded: " << ROFS_ImageSize << " bytes, " << ROFS_Entries
                  << " entries; both font sizes rendered successfully.\n";
        return 0;
    }

    while (adapter::available()) {
        graphics.present();
        Sleep(16);
    }
    return 0;
}
