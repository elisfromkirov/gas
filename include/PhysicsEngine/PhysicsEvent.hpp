#ifndef __PHYSICS_EVENT_HPP__
#define __PHYSICS_EVENT_HPP__

#include "IEvent.hpp"

class IPhysicsEntity;

class CollisionEvent : public IEvent {
public:
    CollisionEvent(IPhysicsEntity* first, IPhysicsEntity* second);
    virtual ~CollisionEvent() override;

    virtual uint32_t GetCategory() const override;

    IPhysicsEntity* GetFirstEntity() const; 
    IPhysicsEntity* GetSecondEntity() const;

private:
    IPhysicsEntity* first_;
    IPhysicsEntity* second_;
};

#endif // __PHYSICS_EVENT_HPP__
