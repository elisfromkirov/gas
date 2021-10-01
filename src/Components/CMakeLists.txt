add_library(GasComponents)

set(INCROOT ${Gas_SOURCE_DIR}/include/Components)

target_include_directories(GasComponents
    PUBLIC
        ${INCROOT}
    )

target_sources(GasComponents
    PUBLIC
        ${INCROOT}/GraphicsComponent.hpp
    PRIVATE
        GraphicsComponent.cpp
    )

target_link_libraries(GasComponents
    PUBLIC
        GasMath
        Gas3DGraphics
    PRIVATE
        m
    )
