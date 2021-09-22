#include "MoleculeEntity.hpp"

#include <stdio.h>

MoleculeEntity::MoleculeEntity(Sphere* sphere, SpherePhysicsComponent* physics_component) 
    : sphere_{sphere}, physics_component_{physics_component} {}

MoleculeEntity::~MoleculeEntity() {}

void MoleculeEntity::Move(const Vector3<float>& displacement) {
    sphere_->SetCenter(sphere_->GetCenter() + displacement);
}

void MoleculeEntity::CollisionResponse(IPhysicsEntity* entity) {}
