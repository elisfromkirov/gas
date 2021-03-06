#ifndef __I_PHYSICS_ENTITY_HPP__
#define __I_PHYSICS_ENTITY_HPP__

#include "Vector3.hpp"

class PhysicsEngine;

class IPhysicsEntity {
public:
    virtual ~IPhysicsEntity() {}

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) = 0;
    
    virtual void UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) = 0;

    virtual void Move(const Vector3<float>& displacement) = 0;
};

#endif // __I_PHYSICS_ENTITY_HPP__
