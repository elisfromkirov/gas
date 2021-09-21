add_library(GasEntity)

set(INCROOT ${Gas_SOURCE_DIR}/include/Entity)

target_include_directories(GasEntity
    PUBLIC
        ${INCROOT}
    )

target_sources(GasEntity
    PUBLIC
        ${INCROOT}/IPhysicsEntity.hpp
        ${INCROOT}/PhysicsEventListener.hpp
    PRIVATE
        PhysicsEventListener.cpp
    )

target_link_libraries(GasEntity
    PUBLIC
        GasMath
        GasPhysics
    )
