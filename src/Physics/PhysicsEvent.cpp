#include "PhysicsEvent.hpp"

MovementEvent::MovementEvent(IPhysicsEntity* entity, const Vector3<float>& displacement) 
    : entity_{entity}, displacement_{displacement} {}

MovementEvent::~MovementEvent() {}

uint32_t MovementEvent::GetCategory() const {
    return kPhysicsEventCategory;
}

uint32_t MovementEvent::GetMask() const {
    return kMovementEventMask;
}

IPhysicsEntity* MovementEvent::GetEntity() const {
    return entity_;
}
    
const Vector3<float>& MovementEvent::GetDisplacement() const {
    return displacement_;
}

CollisionEvent::CollisionEvent(IPhysicsEntity* first_entity, IPhysicsEntity* second_entity)
    : first_entity_{first_entity}, second_entity_{second_entity} {}

CollisionEvent::~CollisionEvent() {}

uint32_t CollisionEvent::GetCategory() const {
    return kPhysicsEventCategory;
}

uint32_t CollisionEvent::GetMask() const {
    return kCollisionEventMask;
}

IPhysicsEntity* CollisionEvent::GetFirstEntity() const {
    return first_entity_;
}

IPhysicsEntity* CollisionEvent::GetSecondEntity() const {
    return second_entity_;
}
