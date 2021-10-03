#include "RigidBody.hpp"

RigidBody::RigidBody(uint32_t type, IPhysicsEntity* entity, const Vector3<float>& velocity, 
                     float mass)
    : type{type}, entity{entity}, velocity{velocity}, mass{mass} {}

SphereBody::SphereBody(IPhysicsEntity* entity, const Vector3<float>& velocity, float mass,
                       const Vector3<float>& center, float radius)
    : RigidBody{kSphereBody, entity, velocity, mass}, center{center}, radius{radius} {}

BoxBody::BoxBody(IPhysicsEntity* entity, const Vector3<float>& velocity, float mass,
                 const Vector3<float>& center, const Vector3<float>& size)
    : RigidBody{kSphereBody, entity, velocity, mass}, center{center}, size{size} {}
