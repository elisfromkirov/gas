add_library(RayTracer-Primitives)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/Primitives)

target_include_directories(RayTracer-Primitives
    PUBLIC
        ${INCROOT}
    )

target_sources(RayTracer-Primitives
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/LightSource.hpp
        ${INCROOT}/List.hpp
        ${INCROOT}/Material.hpp
        ${INCROOT}/Vector2.hpp
        ${INCROOT}/Vector3.hpp
    PRIVATE
        Color.cpp
        LightSource.cpp
        Vector2.cpp
        Vector3.cpp
    )

target_link_libraries(RayTracer-Primitives
    PRIVATE
        m
    )
