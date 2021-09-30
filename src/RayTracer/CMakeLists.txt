add_library(Gas3DGraphics)

set(INCROOT ${Gas_SOURCE_DIR}/include/RayTracer)

target_include_directories(Gas3DGraphics
    PUBLIC
        ${INCROOT}
    )

target_sources(Gas3DGraphics
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/IPrimitive.hpp
        ${INCROOT}/LightSource.hpp
        ${INCROOT}/Material.hpp
        ${INCROOT}/Ray.hpp
        ${INCROOT}/RayTracer.hpp
        ${INCROOT}/Scene.hpp
        ${INCROOT}/Sphere.hpp
        ${INCROOT}/Triangle.hpp
    PRIVATE
        Color.cpp
        LightSource.cpp
        RayTracer.cpp
        Scene.cpp
        Sphere.cpp
        Triangle.cpp
    )

target_link_libraries(Gas3DGraphics
    PUBLIC
        GasMath
        GasPlatform
    PRIVATE
        m
    )
