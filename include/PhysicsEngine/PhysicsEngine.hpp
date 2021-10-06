#ifndef __PHYSICS_ENGINE_HPP__
#define __PHYSICS_ENGINE_HPP__

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

#include "EventManager.hpp"
#include "RigidBody.hpp"

class PhysicsEngine {
public:
    PhysicsEngine(EventManager* event_manager);
    ~PhysicsEngine();

    void RegisterRigidBody(RigidBody* rigid_body);
    void UnregisterRigidBody(RigidBody* rigid_body);

    void SimulatePhysics(float delta_time);

private:
    EventManager* event_manager_;

    std::vector<RigidBody*> rigid_bodies_;
};

#endif // __PHYSICS_ENGINE_HPP__
