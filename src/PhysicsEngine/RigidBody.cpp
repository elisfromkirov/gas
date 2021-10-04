#include "RigidBody.hpp"

RigidBody::RigidBody(uint32_t type, IPhysicsEntity* entity) : type{type}, entity{entity} {}

SphereBody::SphereBody(IPhysicsEntity* entity,
                       const Vector3<float>& center,
                       float radius,
                       const Vector3<float>& velocity,
                       float mass)
    : RigidBody{kSphereBodyType, entity},
      center{center},
      radius{radius}, 
      velocity{velocity},
      mass{mass} {}

WallBody::WallBody(IPhysicsEntity* entity,
                   const Vector3<float>& normal,
                   const Vector3<float>& point)
    : RigidBody{kWallBodyType, entity},
      normal{normal},
      point{point} {}

BoxBody::BoxBody(IPhysicsEntity* entity,
                 const Vector3<float>& center,
                 const Vector3<float>& size,
                 const Vector3<float>& velocity,
                 float mass)
    : RigidBody{kSphereBodyType, entity},
      center{center},
      size{size},
      velocity{velocity},
      mass{mass} {}
