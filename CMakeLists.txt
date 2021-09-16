cmake_minimum_required(VERSION 3.7)

project(RayTracer)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_EXE_LINKER_FLAGS "-lm -lSDL2")

add_executable(RayTracer)

find_package(SDL2 REQUIRED)

include_directories(RayTraycer ${SDL2_INCLUDE_DIRS})

target_sources(RayTracer
    PRIVATE
        src/main.cpp
    )

target_link_libraries(RayTracer
    PUBLIC
        RayTracer-Primitives
        RayTracer-Shape
        RayTracer-RayTracer
        RayTracer-Window
        ${SDL2_LIBRARIES}
    )

add_subdirectory(src/Primitives)
add_subdirectory(src/RayTracer)
add_subdirectory(src/Shape)
add_subdirectory(src/Window)
