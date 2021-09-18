add_library(RayTracer-Shape)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/Shape)

target_include_directories(RayTracer-Shape
    PUBLIC
        ${INCROOT}
    )

target_sources(RayTracer-Shape
    PUBLIC
        ${INCROOT}/IShape.hpp
        ${INCROOT}/Sphere.hpp
        ${INCROOT}/ShapeManager.hpp
    PRIVATE
        Sphere.cpp
        ShapeManager.cpp
    )

target_link_libraries(RayTracer-Shape
    PUBLIC
        RayTracer-Primitives
        RayTracer-RayTracer
    PRIVATE
        m
    )
