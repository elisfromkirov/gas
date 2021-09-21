add_library(GasPhysics)

set(INCROOT ${Gas_SOURCE_DIR}/include/Physics)

target_include_directories(GasPhysics
    PUBLIC
        ${INCROOT}
    )

target_sources(GasPhysics
    PUBLIC
        ${INCROOT}/GeomShape.hpp
        ${INCROOT}/PhysicsComponent.hpp
        ${INCROOT}/PhysicsComponentManager.hpp
        ${INCROOT}/PhysicsEngine.hpp
        ${INCROOT}/PhysicsEvent.hpp
    PRIVATE
        PhysicsComponent.cpp
        PhysicsComponentManager.cpp
        PhysicsEngine.cpp
        PhysicsEvent.cpp
    )

target_link_libraries(GasPhysics
    PUBLIC
        GasEvent
        GasEntity
        GasMath
    PRIVATE
        m
    )
