#include <float.h>
#include <math.h>
#include <stdio.h>

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

#include "Collision.hpp"

bool CollisionDetectSphereSphere(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

bool CollisionDetectSphereBox(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

bool CollisionDetectBoxBox(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

bool CollisionDetectSphereWall(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    SphereBody* sphere = reinterpret_cast<SphereBody*>(lhs);
    WallBody*   wall   = reinterpret_cast<WallBody*>  (rhs);

    float product = DotProduct(wall->normal, sphere->velocity);
    if (IsEqual(product, 0.f)) {
        return false;
    }

    float t = DotProduct(wall->normal,
                         wall->point + wall->normal * sphere->radius - sphere->center) / product;
    if (t < 0.f || delta_time < t) {
        return false;
    }

    *time = t;
    return true;
}

bool CollisionDetectBoxWall(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

bool CollisionDetectWallWall(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

void CollisionResponseSphereSphere(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}

void CollisionResponseSphereBox(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}

void CollisionResponseBoxBox(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}

void CollisionResponseSphereWall(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    SphereBody* sphere = reinterpret_cast<SphereBody*>(lhs);
    WallBody*   wall   = reinterpret_cast<WallBody*>  (rhs);

    sphere->velocity -= wall->normal * (2.f * DotProduct(wall->normal, sphere->velocity));
}

void CollisionResponseBoxWall(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}

void CollisionResponseWallWall(RigidBody* lhs, RigidBody* rhs) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}
