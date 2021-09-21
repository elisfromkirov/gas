#include "PhysicsComponent.hpp"

IPhysicsComponent::IPhysicsComponent(uint32_t type, const Vector3<float>& velocity, float mass) 
    : type{type}, velocity{velocity}, mass{mass} {}

IPhysicsComponent::~IPhysicsComponent() {}

BoxPhysicsComponent::BoxPhysicsComponent(
    const BoxGeom& geom, const Vector3<float>& velocity, float mass)
    : IPhysicsComponent{kBoxPhysicsComponent, velocity, mass}, geom{geom} {}

BoxPhysicsComponent::~BoxPhysicsComponent() {}

SpherePhysicsComponent::SpherePhysicsComponent(
    const SphereGeom& geom, const Vector3<float>& velocity, float mass)
    : IPhysicsComponent{kSpherePhysicsComponent, velocity, mass}, geom{geom} {} 

SpherePhysicsComponent::~SpherePhysicsComponent() {}
