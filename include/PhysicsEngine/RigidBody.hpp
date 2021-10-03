#ifndef __RIGIT_BODY_HPP__
#define __RIGIT_BODY_HPP__

#include "IPhysicsEntity.hpp"

#include <cassert>
#include <cstdint>

enum PhysicsComponentType : uint32_t {
    kSphereBody = 0,
    kBoxBody    = 1
};

struct RigidBody {
    RigidBody(uint32_t type, IPhysicsEntity* entity, const Vector3<float>& velocity, float mass);
    virtual ~RigidBody() {}   

    uint32_t type;
    IPhysicsEntity* entity;

    Vector3<float> velocity;
    float mass;
};

struct SphereBody : public RigidBody {
    SphereBody(IPhysicsEntity* entity, const Vector3<float>& velocity, float mass,
               const Vector3<float>& center, float radius);
    virtual ~SphereBody() override {}
    
    Vector3<float> center;
    float          radius;
};

struct BoxBody : public RigidBody {
    BoxBody(IPhysicsEntity* entity, const Vector3<float>& velocity, float mass,
            const Vector3<float>& center, const Vector3<float>& size);
    virtual ~BoxBody() override {}

    Vector3<float> center;
    Vector3<float> size;
};

#endif // __RIGIT_BODY_HPP__
