#ifndef __PHYSICS_COMPONENT_MANAGER_HPP__
#define __PHYSICS_COMPONENT_MANAGER_HPP__

#include <list>

#include "PhysicsComponent.hpp"
#include "PhysicsEngine.hpp"

class PhysicsManager {
public:
    PhysicsManager();
    ~PhysicsManager();

    void AddPhysicsComponent(IPhysicsComponent* component, IPhysicsEntity* entity);

    void SimulatePhysics(PhysicsEngine& physics_engine);

private:
    std::list<PhysicsEngine::Data> data_;
};

#endif // __PHYSICS_COMPONENT_MANAGER_HPP__
