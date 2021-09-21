#ifndef __PHYSICS_COMPONENT_HPP__
#define __PHYSICS_COMPONENT_HPP__

#include <cstdint>

#include "GeomShape.hpp"
#include "Vector3.hpp"

enum PhysicsComponentType : uint32_t {
    kBoxPhysicsComponent    = 0,
    kSpherePhysicsComponent = 1
};

class IPhysicsComponent {
public:
    IPhysicsComponent(uint32_t type, const Vector3<float>& velocity, float mass);
    virtual ~IPhysicsComponent();

    uint32_t       type;

    Vector3<float> velocity;
    float          mass;
};

class BoxPhysicsComponent : public IPhysicsComponent {
public:
    BoxPhysicsComponent(const BoxGeom& geom, const Vector3<float>& velocity, float mass);
    virtual ~BoxPhysicsComponent();

    BoxGeom        geom;
};

class SpherePhysicsComponent : public IPhysicsComponent {
public:
    SpherePhysicsComponent(const SphereGeom& geom, const Vector3<float>& velocity, float mass);
    virtual ~SpherePhysicsComponent();

    SphereGeom        geom;
};

#endif // __PHYSICS_COMPONENT_HPP__
