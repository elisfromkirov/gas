#ifndef __PHYSICS_ENGINE_HPP__
#define __PHYSICS_ENGINE_HPP__

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

#include "RigidBody.hpp"

class PhysicsEngine {
public:
    void RegisterRigidBody(RigidBody* rigid_body);
    void UnregisterRigidBody(RigidBody* rigid_body);

    void SimulatePhysics(float delta_time);

private:
    std::vector<RigidBody*> rigid_bodies_;
};

#endif // __PHYSICS_ENGINE_HPP__
