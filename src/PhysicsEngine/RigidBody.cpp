#include "RigidBody.hpp"

RigidBody::RigidBody(uint32_t type, 
                     IPhysicsEntity* entity,
                     const Vector3<float>& velocity,
                     float mass)
    : type{type},
      entity{entity},
      velocity{velocity},
      mass{mass} {}

void RigidBody::Move(const Vector3<float>& displacement) {}

SphereBody::SphereBody(IPhysicsEntity* entity,
                       const Vector3<float>& center,
                       float radius,
                       const Vector3<float>& velocity,
                       float mass)
    : RigidBody{kSphereBodyType, entity, velocity, mass},
      center{center},
      radius{radius} {}

void SphereBody::Move(const Vector3<float>& displacement) {
    center += displacement;
}

BoxBody::BoxBody(IPhysicsEntity* entity,
                 const Vector3<float>& center,
                 const Vector3<float>& size,
                 const Vector3<float>& velocity,
                 float mass)
    : RigidBody{kSphereBodyType, entity, velocity, mass},
      center{center},
      size{size} {}

void BoxBody::Move(const Vector3<float>& displacement) {
    center += displacement;
}

WallBody::WallBody(IPhysicsEntity* entity,
                   const Vector3<float>& normal,
                   const Vector3<float>& point)
    : RigidBody{kWallBodyType, entity, Vector3<float>{0.f, 0.f, 0.f}, 0.f},
      normal{normal},
      point{point} {}
