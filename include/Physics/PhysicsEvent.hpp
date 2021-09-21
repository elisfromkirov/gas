#ifndef __PHYSICS_EVENT_HPP__
#define __PHYSICS_EVENT_HPP__

#include <cstdio>

#include "IEvent.hpp"
#include "IPhysicsEntity.hpp"
#include "Vector3.hpp"

enum PhysicsEventMask : uint32_t {
    kNoPhysicsEventMask = kNoneCategoty         | 0x0000,
    kMovementEventMask  = kPhysicsEventCategory | 0x0001,
    kCollisionEventMask = kPhysicsEventCategory | 0x0002
};

class MovementEvent : public IEvent {
public:
    MovementEvent(IPhysicsEntity* entity, const Vector3<float>& displacement);
    virtual ~MovementEvent();

    virtual uint32_t GetCategory() const override;

    virtual uint32_t GetMask() const override;

    IPhysicsEntity* GetEntity() const;
    
    const Vector3<float>& GetDisplacement() const;

private:
    IPhysicsEntity* entity_;
    Vector3<float>  displacement_;
};

class CollisionEvent : public IEvent {
public:
    CollisionEvent(IPhysicsEntity* first_entity, IPhysicsEntity* second_entity);
    virtual ~CollisionEvent();

    virtual uint32_t GetCategory() const override;

    virtual uint32_t GetMask() const override;

    IPhysicsEntity* GetFirstEntity() const;
    IPhysicsEntity* GetSecondEntity() const;

private:
    IPhysicsEntity* first_entity_;
    IPhysicsEntity* second_entity_;
};

#endif // __PHYSICS_EVENT_HPP__
