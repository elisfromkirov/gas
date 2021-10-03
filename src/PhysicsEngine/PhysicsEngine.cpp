#include "PhysicsEngine.hpp"

void PhysicsEngine::RegisterRigidBody(RigidBody* rigid_body) {
    assert(rigid_body != nullptr);

    rigid_bodies_.push_back(rigid_body);
}

void PhysicsEngine::SimulatePhysics() {}
