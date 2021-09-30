add_library(GasPlatform)

set(INCROOT ${Gas_SOURCE_DIR}/include/Platform)

find_package(SDL2 REQUIRED)

target_include_directories(GasPlatform
    PUBLIC
        ${INCROOT}
        ${SDL2_INCLUDE_DIRS}
    )

target_sources(GasPlatform
    PUBLIC
        ${INCROOT}/Window.hpp
        ${INCROOT}/WindowSurface.hpp
    PRIVATE
        Window.cpp
        WindowSurface.cpp
    )
