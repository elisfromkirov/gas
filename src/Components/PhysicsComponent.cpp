#include "PhysicsComponent.hpp"

SpherePhysicsComponent::SpherePhysicsComponent(
    IPhysicsEntity* entity, const Vector3<float>& center, float radius,
    const Vector3<float>& velocity, float mass) 
    : sphere_{entity, velocity, mass, center, radius} {} 

void SpherePhysicsComponent::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    physics_engine->RegisterRigidBody(&sphere_);
}
