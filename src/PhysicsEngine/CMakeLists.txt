add_library(GasPhysics)

set(INCROOT ${Gas_SOURCE_DIR}/include/PhysicsEngine)

target_include_directories(GasPhysics
    PUBLIC
        ${INCROOT}
    )

target_sources(GasPhysics
    PUBLIC
        ${INCROOT}/Collision.hpp
        ${INCROOT}/PhysicsEngine.hpp
        ${INCROOT}/PhysicsEvent.hpp
        ${INCROOT}/RigidBody.hpp
    PRIVATE
        Collision.cpp
        PhysicsEngine.cpp
        PhysicsEvent.cpp
        RigidBody.cpp
    )

target_link_libraries(GasPhysics
    PUBLIC
        GasEvent
        GasGas    
        GasMath    
    PRIVATE
        m
    )
