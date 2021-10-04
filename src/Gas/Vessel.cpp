#include "Vessel.hpp"

Vessel::Vessel() : graphics_component_{}, physics_component_{this} {}

Vessel::~Vessel() {}

IGraphicsComponent* Vessel::GetGraphicsComponent() {
    return &graphics_component_;
}

IPhysicsComponent* Vessel::GetPhysicsComponent() {
    return &physics_component_;
}

void Vessel::Move(const Vector3<float>& displacement) {}

void Vessel::CollisionResponse(IPhysicsEntity* entity) {}
