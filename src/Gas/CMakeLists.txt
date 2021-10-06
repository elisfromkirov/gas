add_library(GasGas)

set(INCROOT ${Gas_SOURCE_DIR}/include/Gas)

target_include_directories(GasGas
    PUBLIC
        ${INCROOT}
    )

target_sources(GasGas
    PUBLIC
        ${INCROOT}/BoxMolecule.hpp
        ${INCROOT}/IGraphicsEntity.hpp
        ${INCROOT}/IMolecule.hpp
        ${INCROOT}/IPhysicsEntity.hpp
        ${INCROOT}/MoleculeManager.hpp
        ${INCROOT}/SphereMolecule.hpp
        ${INCROOT}/Vessel.hpp
    PRIVATE
        BoxMolecule.cpp
        MoleculeManager.cpp
        SphereMolecule.cpp
        Vessel.cpp
    )

target_link_libraries(GasGas
    PUBLIC
        GasEvent
        GasMath
        Gas3DGraphics
        GasPhysics
    PRIVATE
        m
    )
