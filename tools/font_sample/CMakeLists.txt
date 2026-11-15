cmake_minimum_required(VERSION 3.22)
project(micronix-font-sample CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Freetype REQUIRED)

add_executable(micronix-font-sample font_sample.cpp)
target_include_directories(micronix-font-sample PRIVATE ../../include)
target_include_directories(micronix-font-sample PRIVATE ../common/cpp)
target_link_libraries(micronix-font-sample PRIVATE Freetype::Freetype)
