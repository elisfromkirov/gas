#include "Molecule.hpp"

SphereMolecule::SphereMolecule(const Vector3<float>& center, float radius, 
                               const Vector3<float>& velocity, const Material* material)
    : graphics_component_{center, radius, material},
      physics_component_{this, center, 1.f, velocity, radius} {}

SphereMolecule::~SphereMolecule() {}

IGraphicsComponent* SphereMolecule::GetGraphicsComponent() {
    return &graphics_component_;
}

IPhysicsComponent* SphereMolecule::GetPhysicsComponent() {
    return &physics_component_;
}

void SphereMolecule::Move(const Vector3<float>& displacement) {
    graphics_component_.Move(displacement);
}

void SphereMolecule::CollisionResponse(IPhysicsEntity* entity) {}
