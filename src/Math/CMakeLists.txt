add_library(GasMath)

set(INCROOT ${RayTracer_SOURCE_DIR}/include/Math)

target_include_directories(GasMath
    PUBLIC
        ${INCROOT}
    )

target_sources(GasMath
    PUBLIC
        ${INCROOT}/Vector2.hpp
        ${INCROOT}/Vector3.hpp
    PRIVATE
        Vector2.cpp
        Vector3.cpp
    )

target_link_libraries(GasMath
    PRIVATE
        m
    )
