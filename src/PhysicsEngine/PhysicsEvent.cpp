#include "PhysicsEvent.hpp"

CollisionEvent::CollisionEvent(IPhysicsEntity* first, IPhysicsEntity* second)
    : first_{first}, second_{second} {}

CollisionEvent::~CollisionEvent() {}

uint32_t CollisionEvent::GetCategory() const {
    return kCollisionEventCategory;
}

IPhysicsEntity* CollisionEvent::GetFirstEntity() const {
    return first_;
}
    
IPhysicsEntity* CollisionEvent::GetSecondEntity() const {
    return second_;
}
