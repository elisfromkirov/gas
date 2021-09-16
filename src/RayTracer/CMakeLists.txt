add_library(RayTracer-RayTracer)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/RayTracer)

target_include_directories(RayTracer-RayTracer
    PUBLIC
        ${INCROOT}
    )

target_sources(RayTracer-RayTracer
    PUBLIC
        ${INCROOT}/Ray.hpp
        ${INCROOT}/RayTracer.hpp
    PRIVATE
        RayTracer.cpp
    )

target_link_libraries(RayTracer-RayTracer
    PUBLIC
        RayTracer-Shape
        RayTracer-Primitives
        RayTracer-Window
    PRIVATE
        m
    )
