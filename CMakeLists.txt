cmake_minimum_required(VERSION 3.7)

project(Gas)

set(CMAKE_CXX_FLAGS "-std=c++11 -W -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field")
set(CMAKE_EXE_LINKER_FLAGS "-lm -lSDL2")

add_executable(Gas)

find_package(SDL2 REQUIRED)

include_directories(Gas ${SDL2_INCLUDE_DIRS})

target_sources(Gas
    PRIVATE
        src/main.cpp
    )

target_link_libraries(Gas
    PUBLIC
        Gas3DGraphics
        GasEntity
        GasEvent
        GasGas
        GasMath
        GasPhysics
        GasWindow
        ${SDL2_LIBRARIES}
    )

add_subdirectory(src/3DGraphics)
add_subdirectory(src/Entity)
add_subdirectory(src/Event)
add_subdirectory(src/Gas)
add_subdirectory(src/Math)
add_subdirectory(src/Physics)
add_subdirectory(src/Window)
