#include "Molecule.hpp"

SphereMolecule::SphereMolecule(const Vector3<float>& center, float radius, const Material* material) 
    : graphics_component_{center, radius, material},
      physics_component_{this, Vector3<float>{0.f, 0.f, 0.f}, 0.f, center, radius} {}

IGraphicsComponent* SphereMolecule::GetGraphicsComponent() {
    return &graphics_component_;
}

IPhysicsComponent* SphereMolecule::GetPhysicsComponent() {
    return &physics_component_;
}

void SphereMolecule::Move(const Vector3<float>& displacement) {}

void SphereMolecule::CollisionResponse(IPhysicsEntity* entity) {}
