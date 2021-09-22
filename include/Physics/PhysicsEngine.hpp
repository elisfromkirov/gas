#ifndef __PHYSICS_ENGINE_HPP__
#define __PHYSICS_ENGINE_HPP__

#include <list>

#include "EventManager.hpp"
#include "IPhysicsEntity.hpp"
#include "PhysicsComponent.hpp"
#include "PhysicsEventListener.hpp"

struct Component {
    IPhysicsComponent* component;
    IPhysicsEntity*    entity;
};

class PhysicsEngine {
public:
    PhysicsEngine(EventManager* event_manager);
    ~PhysicsEngine();

    void SimulatePhysics(std::list<Component>& data);

private:
    EventManager*        event_manager_;
};

// -------------------------------------------------------------------------- //

bool DetectCollision(const BoxPhysicsComponent* lhs, const BoxPhysicsComponent* rhs, 
                     float delta_time, float* collision_time);

bool DetectCollision(const BoxPhysicsComponent* lhs, const SpherePhysicsComponent* rhs, 
                     float delta_time, float* collision_time);

bool DetectCollision(const SpherePhysicsComponent* lhs, const SpherePhysicsComponent* rhs, 
                     float delta_time, float* collision_time);

void CollisionResponse(BoxPhysicsComponent* lhs, BoxPhysicsComponent* rhs,
                       float collision_time);

void CollisionResponse(BoxPhysicsComponent* lhs, SpherePhysicsComponent* rhs,
                       float collision_time);

void CollisionResponse(SpherePhysicsComponent* lhs, SpherePhysicsComponent* rhs,
                       float collision_time);

#endif // __PHYSICS_ENGINE_HPP__
