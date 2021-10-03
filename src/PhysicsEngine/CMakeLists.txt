add_library(GasPhysics)

set(INCROOT ${Gas_SOURCE_DIR}/include/PhysicsEngine)

target_include_directories(GasPhysics
    PUBLIC
        ${INCROOT}
    )

target_sources(GasPhysics
    PUBLIC
        ${INCROOT}/PhysicsEngine.hpp
        ${INCROOT}/RigidBody.hpp
    PRIVATE
        PhysicsEngine.cpp
        RigidBody.cpp
    )

target_link_libraries(GasPhysics
    PUBLIC
        GasMath
        GasComponents
    PRIVATE
        m
    )
