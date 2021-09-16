add_library(RayTracer-Window)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/Window)

find_package(SDL2 REQUIRED)

target_include_directories(RayTracer-Window
    PUBLIC
        ${INCROOT}
        ${SDL2_INCLUDE_DIRS}
    )

target_sources(RayTracer-Window
    PUBLIC
        ${INCROOT}/Window.hpp
        ${INCROOT}/Surface.hpp
    PRIVATE
        Window.cpp
        Surface.cpp
    )

target_link_libraries(RayTracer-Window
    PUBLIC
        RayTracer-Primitives
    )
