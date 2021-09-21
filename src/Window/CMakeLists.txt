add_library(GasWindow)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/Window)

find_package(SDL2 REQUIRED)

target_include_directories(GasWindow
    PUBLIC
        ${INCROOT}
        ${SDL2_INCLUDE_DIRS}
    )

target_sources(GasWindow
    PUBLIC
        ${INCROOT}/Window.hpp
        ${INCROOT}/Surface.hpp
    PRIVATE
        Window.cpp
        Surface.cpp
    )
