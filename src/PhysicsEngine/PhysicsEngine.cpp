#include <stdio.h>

#include "Collision.hpp"
#include "PhysicsEngine.hpp"

void PhysicsEngine::RegisterRigidBody(RigidBody* rigid_body) {
    assert(rigid_body != nullptr);

    rigid_bodies_.push_back(rigid_body);
}

void PhysicsEngine::SimulatePhysics(float delta_time) {
    std::vector<Collision> collisions(rigid_bodies_.size());

    for (uint32_t i = 0; i < rigid_bodies_.size(); ++i) {
        for (uint32_t j = i + 1; j < rigid_bodies_.size(); ++j) {
            RigidBody* lhs = rigid_bodies_.at(i);
            RigidBody* rhs = rigid_bodies_.at(j);

            if (rhs->type < lhs->type) {
                std::swap(lhs, rhs);
            }

            uint32_t index = kCollisionDetectIndexTable[lhs->type][rhs->type];
            if (index == kInvalidIndex) {
                continue;
            }

            if (kCollisionDetectTable[index](lhs, rhs, delta_time, &collisions.at(i).collision_time)) {            
                collisions.at(i).lhs          = i;
                collisions.at(i).rhs          = j;
                collisions.at(i).is_detected  = true;
                collisions.at(i).is_processed = false;

                collisions.at(j) = collisions.at(i);
            }
        }
    }

    for (uint32_t i = 0; i < rigid_bodies_.size(); ++i) {
        if (collisions.at(i).is_detected) {
            if (collisions.at(i).is_processed) {
                continue;
            }
            collisions.at(collisions.at(i).lhs).is_processed = true;
            collisions.at(collisions.at(i).rhs).is_processed = true;
            
            RigidBody* lhs = rigid_bodies_.at(collisions.at(i).lhs);
            RigidBody* rhs = rigid_bodies_.at(collisions.at(i).rhs);

            if (rhs->type < lhs->type) {
                std::swap(lhs, rhs);
            }

            Vector3<float> lhs_displacement{lhs->velocity * collisions.at(i).collision_time};
            Vector3<float> rhs_displacement{lhs->velocity * collisions.at(i).collision_time};

            uint32_t index = kCollisionDetectIndexTable[lhs->type][rhs->type];
            if (index == kInvalidIndex) {
                continue;
            }  
            kCollisionResponseTable[index](lhs, rhs);

            lhs_displacement += lhs->velocity * (delta_time - collisions.at(i).collision_time);
            rhs_displacement += rhs->velocity * (delta_time - collisions.at(i).collision_time);

            lhs->Move(lhs_displacement);
            lhs->entity->Move(lhs_displacement);

            rhs->Move(rhs_displacement);
            rhs->entity->Move(rhs_displacement);
        } else {
            RigidBody* rigid_body = rigid_bodies_.at(i);
            
            Vector3<float> displacement{rigid_body->velocity * delta_time};

            rigid_body->Move(displacement);
            rigid_body->entity->Move(displacement);
        }
    }
}
