#include "PhysicsEngine.hpp"    

PhysicsEngine::PhysicsEngine(EventManager* event_manager) 
    : event_manager_{event_manager} {}

PhysicsEngine::~PhysicsEngine() {}

void PhysicsEngine::SimulatePhysics(std::list<Data>& data) {
    // TODO: Write code!
}

// -------------------------------------------------------------------------- //

bool DetectCollision(const BoxPhysicsComponent* lhs, const BoxPhysicsComponent* rhs, 
                     float delta_time, float* collision_time) {
    // TODO: Write code!
}

bool DetectCollision(const BoxPhysicsComponent* lhs, const SpherePhysicsComponent* rhs, 
                     float delta_time, float* collision_time) {
    // TODO: Write code!
}

bool DetectCollision(const SpherePhysicsComponent* lhs, const SpherePhysicsComponent* rhs, 
                     float delta_time, float* collision_time) {
    // TODO: Write code!
}

void CollisionResponse(BoxPhysicsComponent* lhs, BoxPhysicsComponent* rhs,
                       float collision_time) {
    // TODO: Write code!
}

void CollisionResponse(BoxPhysicsComponent* lhs, SpherePhysicsComponent* rhs,
                       float collision_time) {
    // TODO: Write code!
}

void CollisionResponse(SpherePhysicsComponent* lhs, SpherePhysicsComponent* rhs,
                       float collision_time) {
    // TODO: Write code!
}
