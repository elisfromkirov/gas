#include "PhysicsComponentManager.hpp"

PhysicsManager::PhysicsManager() {}

PhysicsManager::~PhysicsManager() {
    for (auto iterator = data_.begin(); iterator != data_.end(); ++iterator) {
        PhysicsEngine::Data record = *iterator;

        delete record.component;
    }
}

void PhysicsManager::AddPhysicsComponent(IPhysicsComponent* component, IPhysicsEntity* entity) {
    data_.push_back(PhysicsEngine::Data{component, entity});
}

void PhysicsManager::SimulatePhysics(PhysicsEngine& physics_engine) {
    physics_engine.SimulatePhysics(data_);
}
