#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

#include <cassert>
#include <cstdint>

#include "RigidBody.hpp"

struct Collision {
    uint32_t lhs;
    uint32_t rhs;
    float    collision_time;

    bool     is_detected;
    bool     is_processed;
};

const uint32_t kInvalidIndex = UINT32_MAX;

static uint32_t kCollisionDetectIndexTable[3][3] = {
    {            0,             1,             3},
    {kInvalidIndex,             2,             4},
    {kInvalidIndex, kInvalidIndex,             5}
};

bool CollisionDetectSphereSphere(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);
bool CollisionDetectSphereBox   (RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);
bool CollisionDetectBoxBox      (RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);
bool CollisionDetectSphereWall  (RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);
bool CollisionDetectBoxWall     (RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);
bool CollisionDetectWallWall    (RigidBody* lhs, RigidBody* rhs, float delta_time, float* time);

typedef bool (*CollisionDetectFunction)(RigidBody*, RigidBody*, float, float*);

static CollisionDetectFunction kCollisionDetectTable[6] = {
    CollisionDetectSphereSphere,
    CollisionDetectSphereBox,
    CollisionDetectBoxBox,
    CollisionDetectSphereWall,
    CollisionDetectBoxWall,
    CollisionDetectWallWall
};

void CollisionResponseSphereSphere(RigidBody* lhs, RigidBody* rhs);
void CollisionResponseSphereBox   (RigidBody* lhs, RigidBody* rhs);
void CollisionResponseBoxBox      (RigidBody* lhs, RigidBody* rhs);
void CollisionResponseSphereWall  (RigidBody* lhs, RigidBody* rhs);
void CollisionResponseBoxWall     (RigidBody* lhs, RigidBody* rhs);
void CollisionResponseWallWall    (RigidBody* lhs, RigidBody* rhs);

typedef void (*CollisionResponseFunction)(RigidBody*, RigidBody*);

static CollisionResponseFunction kCollisionResponseTable[6] = {
    CollisionResponseSphereSphere,
    CollisionResponseSphereBox,
    CollisionResponseBoxBox,
    CollisionResponseSphereWall,
    CollisionResponseBoxWall,
    CollisionResponseWallWall
};

#endif // __COLLISION_HPP__
