add_library(Gas3DGraphics)

set(INCROOT ${Gas_SOURCE_DIR}/include/RayTracer)

target_include_directories(Gas3DGraphics
    PUBLIC
        ${INCROOT}
    )

target_sources(Gas3DGraphics
    PUBLIC
        ${INCROOT}/Box.hpp
        ${INCROOT}/Camera.hpp
        ${INCROOT}/Color.hpp
        ${INCROOT}/IPrimitive.hpp
        ${INCROOT}/LightSource.hpp
        ${INCROOT}/Material.hpp
        ${INCROOT}/Ray.hpp
        ${INCROOT}/RayTracer.hpp
        ${INCROOT}/Scene.hpp
        ${INCROOT}/Sphere.hpp
        ${INCROOT}/Surface.hpp
        ${INCROOT}/Triangle.hpp
    PRIVATE
        Box.cpp
        Camera.cpp
        Color.cpp
        LightSource.cpp
        RayTracer.cpp
        Scene.cpp
        Sphere.cpp
        Surface.cpp
        Triangle.cpp
    )

target_link_libraries(Gas3DGraphics
    PUBLIC
        GasMath
        GasPlatform
    PRIVATE
        m
    )
