add_library(GasMath)

set(INCROOT ${Gas_SOURCE_DIR}/include/Math)

target_include_directories(GasMath
    PUBLIC
        ${INCROOT}
    )

target_sources(GasMath
    PUBLIC
        ${INCROOT}/Matrix2x2.hpp
        ${INCROOT}/Matrix4x4.hpp
        ${INCROOT}/Vector2.hpp
        ${INCROOT}/Vector3.hpp
    PRIVATE
        Matrix4x4.cpp
        Vector2.cpp
        Vector3.cpp
    )

target_link_libraries(GasMath
    PRIVATE
        m
    )
