add_library(GasGas)

set(INCROOT ${Gas_SOURCE_DIR}/include/Gas)

target_include_directories(GasGas
    PUBLIC
        ${INCROOT}
    )

target_sources(GasGas
    PUBLIC
        ${INCROOT}/MoleculeEntity.hpp
        ${INCROOT}/VesselEntity.hpp
    PRIVATE
        MoleculeEntity.cpp
        VesselEntity.cpp
    )

target_link_libraries(GasGas
    PUBLIC
        Gas3DGraphics
        GasEntity
        GasMath
        GasPhysics
    )
