#ifndef __PHYSICS_EVENT_LISTENER_HPP__
#define __PHYSICS_EVENT_LISTENER_HPP__

#include "IEvent.hpp"
#include "IEventListener.hpp"
#include "PhysicsEvent.hpp"

class PhysicsEventListener : public IEventListener {
public:
    PhysicsEventListener();
    virtual ~PhysicsEventListener();

    virtual void OnEvent(const IEvent* event) override;
};

#endif // __PHYSICS_EVENT_LISTENER_HPP__
