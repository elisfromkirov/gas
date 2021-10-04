#ifndef __RIGIT_BODY_HPP__
#define __RIGIT_BODY_HPP__

#include "IPhysicsEntity.hpp"

#include <cassert>
#include <cstdint>

enum PhysicsComponentType : uint32_t {
    kSphereBodyType = 0,
    kBoxBodyType    = 1,
    kWallBodyType   = 2
};

struct RigidBody {
    RigidBody(uint32_t type, IPhysicsEntity* entity, const Vector3<float>& velocity, float mass);

    virtual void Move(const Vector3<float>& displacement);

    uint32_t type;
    IPhysicsEntity* entity;

    Vector3<float> velocity;
    float mass;
};

struct SphereBody : public RigidBody {
    SphereBody(IPhysicsEntity* entity, const Vector3<float>& center, float radius,
               const Vector3<float>& velocity, float mass);

    virtual void Move(const Vector3<float>& displacement) override;

    Vector3<float> center;
    float          radius;

};

struct BoxBody : public RigidBody {
    BoxBody(IPhysicsEntity* entity, const Vector3<float>& center, const Vector3<float>& size,
            const Vector3<float>& velocity, float mass);

    virtual void Move(const Vector3<float>& displacement) override;

    Vector3<float> center;
    Vector3<float> size;
};

struct WallBody : public RigidBody {
    WallBody(IPhysicsEntity* entity, const Vector3<float>& normal, const Vector3<float>& point);

    Vector3<float> normal;
    Vector3<float> point;
};

#endif // __RIGIT_BODY_HPP__
