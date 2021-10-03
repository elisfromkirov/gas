#ifndef __I_PHYSICS_ENTITY_HPP__
#define __I_PHYSICS_ENTITY_HPP__

#include "Vector3.hpp"

class IPhysicsComponent;

class IPhysicsEntity {
public:
    virtual ~IPhysicsEntity() {}

    virtual IPhysicsComponent* GetPhysicsComponent() = 0;

    virtual void Move(const Vector3<float>& displacement) = 0;

    virtual void CollisionResponse(IPhysicsEntity* entity) = 0;
};

#endif // __I_PHYSICS_ENTITY_HPP__
