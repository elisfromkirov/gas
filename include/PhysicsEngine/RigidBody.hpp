#ifndef __RIGIT_BODY_HPP__
#define __RIGIT_BODY_HPP__

#include "IPhysicsEntity.hpp"

#include <cassert>
#include <cstdint>

enum PhysicsComponentType : uint32_t {
    kSphereBodyType = 0,
    kWallBodyType   = 1,
    kBoxBodyType    = 2
};

struct RigidBody {
    RigidBody(uint32_t type, IPhysicsEntity* entity);

    uint32_t type;
    IPhysicsEntity* entity;
};

struct SphereBody : public RigidBody {
    SphereBody(IPhysicsEntity* entity, const Vector3<float>& center, float radius,
               const Vector3<float>& velocity, float mass);
    
    Vector3<float> center;
    float          radius;

    Vector3<float> velocity;
    float mass;
};

struct WallBody : public RigidBody {
    WallBody(IPhysicsEntity* entity, const Vector3<float>& normal, const Vector3<float>& point);

    Vector3<float> normal;
    Vector3<float> point;
};

struct BoxBody : public RigidBody {
    BoxBody(IPhysicsEntity* entity, const Vector3<float>& center, const Vector3<float>& size,
            const Vector3<float>& velocity, float mass);

    Vector3<float> center;
    Vector3<float> size;
    
    Vector3<float> velocity;
    float mass;
};

#endif // __RIGIT_BODY_HPP__
