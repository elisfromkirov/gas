#include "Molecule.hpp"

SphereMolecule::SphereMolecule(const Vector3<float>& center, float radius, const Material* material) 
    : graphics_component_{center, radius, material} {}

IGraphicsComponent* SphereMolecule::GetGraphicsComponent() {
    return &graphics_component_;
}
