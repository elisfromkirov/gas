#include "PhysicsEventListener.hpp"

PhysicsEventListener::PhysicsEventListener() {}

PhysicsEventListener::~PhysicsEventListener() {}

void PhysicsEventListener::OnEvent(const IEvent* event) {
    switch (event->GetMask()) {
        case kMovementEventMask: {
            MovementEvent* movement_event = (MovementEvent*)event;

            movement_event->GetEntity()->Move(movement_event->GetDisplacement());
        } break;
        case kCollisionEventMask: {
            CollisionEvent* collisoon_event = (CollisionEvent*)event;

            collisoon_event->GetFirstEntity()->CollisionResponse(collisoon_event->GetSecondEntity());
            collisoon_event->GetSecondEntity()->CollisionResponse(collisoon_event->GetFirstEntity());
        } break;
    }
}
