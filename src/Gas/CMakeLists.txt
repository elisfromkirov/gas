add_library(GasGas)

set(INCROOT ${Gas_SOURCE_DIR}/include/Gas)

target_include_directories(GasGas
    PUBLIC
        ${INCROOT}
    )

target_sources(GasGas
    PUBLIC
        ${INCROOT}/Molecule.hpp
        ${INCROOT}/MoleculeManager.hpp
    PRIVATE
        Molecule.cpp
        MoleculeManager.cpp
    )

target_link_libraries(GasGas
    PUBLIC
        GasMath
        Gas3DGraphics
        GasComponents
    PRIVATE
        m
    )
