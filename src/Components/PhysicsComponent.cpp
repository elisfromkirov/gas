#include "PhysicsComponent.hpp"

SpherePhysicsComponent::SpherePhysicsComponent(
    IPhysicsEntity* entity, const Vector3<float>& center, float radius,
    const Vector3<float>& velocity, float mass) 
    : sphere_{entity, center, radius, velocity, mass} {} 

SpherePhysicsComponent::~SpherePhysicsComponent() {}

void SpherePhysicsComponent::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    physics_engine->RegisterRigidBody(&sphere_);
}

VesselPhysicsComponent::VesselPhysicsComponent(IPhysicsEntity* entity)
    : near_  {entity, Vector3<float>{-1.f,  0.f,  0.f}, Vector3<float>{ 1.f,  0.f,  0.f}},
      far_   {entity, Vector3<float>{ 1.f,  0.f,  0.f}, Vector3<float>{-1.f,  0.f,  0.f}},
      left_  {entity, Vector3<float>{ 0.f,  1.f,  0.f}, Vector3<float>{ 0.f, -1.f,  0.f}},
      right_ {entity, Vector3<float>{ 0.f, -1.f,  0.f}, Vector3<float>{ 0.f,  1.f,  0.f}},
      top_   {entity, Vector3<float>{ 0.f,  0.f, -1.f}, Vector3<float>{ 0.f,  0.f,  1.f}},
      bottom_{entity, Vector3<float>{ 0.f,  0.f,  1.f}, Vector3<float>{ 0.f,  0.f, -1.f}} {}

VesselPhysicsComponent::~VesselPhysicsComponent() {}

void VesselPhysicsComponent::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->RegisterRigidBody(&near_);
    physics_engine->RegisterRigidBody(&far_);
    physics_engine->RegisterRigidBody(&left_);
    physics_engine->RegisterRigidBody(&right_);
    physics_engine->RegisterRigidBody(&top_);
    physics_engine->RegisterRigidBody(&bottom_);
}
