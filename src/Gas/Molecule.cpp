#include "Molecule.hpp"

SphereMolecule::SphereMolecule(const Vector3<float>& center, float radius, const Material* material) 
    : sphere_{center, radius, material} {}

SphereMolecule::~SphereMolecule() {}

IPrimitive* SphereMolecule::GetGraphicsComponent() {
    return &sphere_;
}