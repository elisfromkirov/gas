#include "PhysicsComponentManager.hpp"

PhysicsManager::PhysicsManager() {}

PhysicsManager::~PhysicsManager() {
    for (auto& component : components_) {
        delete component.component;
    }
}

void PhysicsManager::AddPhysicsComponent(IPhysicsComponent* component, IPhysicsEntity* entity) {
    components_.push_back(Component{component, entity});
}

void PhysicsManager::SimulatePhysics(PhysicsEngine& physics_engine) {
    physics_engine.SimulatePhysics(components_);
}
