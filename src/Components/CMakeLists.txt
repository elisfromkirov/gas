add_library(GasComponents)

set(INCROOT ${Gas_SOURCE_DIR}/include/Components)

target_include_directories(GasComponents
    PUBLIC
        ${INCROOT}
    )

target_sources(GasComponents
    PUBLIC
        ${INCROOT}/GraphicsComponent.hpp
        ${INCROOT}/IGraphicsEntity.hpp
        ${INCROOT}/IPhysicsEntity.hpp
        ${INCROOT}/PhysicsComponent.hpp
    PRIVATE
        GraphicsComponent.cpp
        PhysicsComponent.cpp
    )

target_link_libraries(GasComponents
    PUBLIC
        GasGas    
        GasMath
        Gas3DGraphics
        GasPhysics
    PRIVATE
        m
    )
