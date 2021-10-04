#ifndef __PHYSICS_COMPONENT_HPP__
#define __PHYSICS_COMPONENT_HPP__

#include <cassert>
#include <cstdint>

#include "IPhysicsEntity.hpp"
#include "PhysicsEngine.hpp"
#include "RigidBody.hpp"

class IPhysicsComponent {
public:
    virtual ~IPhysicsComponent() {}

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) = 0;
};

class SpherePhysicsComponent : public IPhysicsComponent {
public:
    SpherePhysicsComponent(IPhysicsEntity* entity, const Vector3<float>& center, float radius,
                           const Vector3<float>& velocity, float mass);

    virtual ~SpherePhysicsComponent() override;

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;

private:
    SphereBody sphere_;
};

class VesselPhysicsComponent : public IPhysicsComponent {
public:
    VesselPhysicsComponent(IPhysicsEntity* entity);

    virtual ~VesselPhysicsComponent() override;

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;

private:
    WallBody near_;
    WallBody far_;
    WallBody left_;
    WallBody right_;
    WallBody top_;
    WallBody bottom_;
};

#endif // __PHYSICS_COMPONENT_HPP__
