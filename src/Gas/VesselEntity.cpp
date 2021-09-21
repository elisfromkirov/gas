#include "VesselEntity.hpp"

VesselEntity::VesselEntity(BoxPhysicsComponent* near, BoxPhysicsComponent* far,
                           BoxPhysicsComponent* left, BoxPhysicsComponent* right,
                           BoxPhysicsComponent* top,  BoxPhysicsComponent* bottom)
    : near_{near}, far_{far}, left_{left}, right_{right}, top_{top}, bottom_{bottom} {}

VesselEntity::~VesselEntity() {}

void Move(const Vector3<float>& displacement) {}

void CollisionResponse(IPhysicsEntity* entity) {}
