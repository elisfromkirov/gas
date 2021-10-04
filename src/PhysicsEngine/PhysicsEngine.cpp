#include <vector>

// #include <stdio.h>

#include "PhysicsEngine.hpp"

void PhysicsEngine::RegisterRigidBody(RigidBody* rigid_body) {
    assert(rigid_body != nullptr);

    rigid_bodies_.push_back(rigid_body);
}

void PhysicsEngine::SimulatePhysics(float delta_time) {
    for (auto rigid_body : rigid_bodies_) {
        if (rigid_body->type == kSphereBodyType) {
            SphereBody* sphere = reinterpret_cast<SphereBody*>(rigid_body);
            sphere->entity->Move(sphere->velocity * delta_time);
        }
    }
}
