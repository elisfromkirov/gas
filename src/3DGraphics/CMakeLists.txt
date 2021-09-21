add_library(Gas3DGraphics)

set(INCROOT ${Gas_SOURCE_DIR}/include/3DGraphics)

target_include_directories(Gas3DGraphics
    PUBLIC
        ${INCROOT}
    )

target_sources(Gas3DGraphics
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/LightSource.hpp
        ${INCROOT}/Material.hpp
        ${INCROOT}/Primitive.hpp
        ${INCROOT}/PrimitiveManager.hpp
        ${INCROOT}/Ray.hpp
        ${INCROOT}/RayTracer.hpp
    PRIVATE
        Color.cpp
        LightSource.cpp
        Primitive.cpp
        PrimitiveManager.cpp
        RayTracer.cpp
    )

target_link_libraries(Gas3DGraphics
    PUBLIC
        GasMath
        GasWindow
    PRIVATE
        m
    )
