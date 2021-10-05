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

    SphereBody* first_sphere  = reinterpret_cast<SphereBody*>(lhs);
    SphereBody* second_sphere = reinterpret_cast<SphereBody*>(rhs);

    Vector3<float> center_difference  {first_sphere->center   - second_sphere->center  };
    Vector3<float> velocity_difference{first_sphere->velocity - second_sphere->velocity};
    
    float distanse = first_sphere->radius + second_sphere->radius;

    float a = DotProduct(velocity_difference, velocity_difference);
    float b = DotProduct(velocity_difference, center_difference  );
    float c = DotProduct(center_difference,   center_difference  ) - distanse * distanse;
    float d = b * b - a * c;

    if (d < 0.0f) {
        return false;
    }

    float roots[] = {std::min((-b - sqrt(d))/a, (-b + sqrt(d))/a),
                     std::max((-b - sqrt(d))/a, (-b + sqrt(d))/a)};

    if (0.f < roots[0] && roots[0] < delta_time) {
        *time = roots[0];
        return true;
    }

    if (0.f < roots[1] && roots[1] < delta_time) {
        *time = roots[1];
        return true;
    }

    return false;
}

bool CollisionDetectSphereBox(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    // TODO: Write code!

    return false;
}

bool CollisionDetectBoxBox(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    // TODO: Write code!

    return false;
}

bool CollisionDetectSphereWall(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    SphereBody* sphere = reinterpret_cast<SphereBody*>(lhs);
    WallBody*   wall   = reinterpret_cast<WallBody*>  (rhs);

    float product = DotProduct(wall->normal, sphere->velocity);
    if (IsEqual(product, 0.0)) {
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

    BoxBody*  box  = reinterpret_cast<BoxBody*> (lhs);
    WallBody* wall = reinterpret_cast<WallBody*>(rhs);

    float product = DotProduct(wall->normal, box->velocity);
    if (IsEqual(product, 0.0)) {
        return false;
    }

    float t = DotProduct(wall->normal, wall->point + wall->normal * DotProduct(wall->normal, box->size) - box->center) / product;
    if (t < 0.f || delta_time < t) {
        return false;
    }

    *time = t;
    return false;
}

bool CollisionDetectWallWall(RigidBody* lhs, RigidBody* rhs, float delta_time, float* time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    return false;
}

void CollisionResponseSphereSphere(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    SphereBody* first_sphere  = reinterpret_cast<SphereBody*>(lhs);
    SphereBody* second_sphere = reinterpret_cast<SphereBody*>(rhs);

    Vector3<float> normal{Normalize(
        (first_sphere->center   - second_sphere->center  ) +
        (first_sphere->velocity - second_sphere->velocity) * collision_time)};

    Vector3<float> first_velocity {normal * DotProduct(first_sphere->velocity,  normal)};
    Vector3<float> second_velocity{normal * DotProduct(second_sphere->velocity, normal)};

    first_sphere->velocity += 
        (second_velocity - first_velocity) * 
        (2.f * second_sphere->mass / (second_sphere->mass + second_sphere->mass));

    second_sphere->velocity += 
        (first_velocity - second_velocity) * 
        (2.f * first_sphere->mass / (second_sphere->mass + second_sphere->mass));
}

void CollisionResponseSphereBox(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    // TODO: Write code!
}

void CollisionResponseBoxBox(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    // TODO: Write code!
}

void CollisionResponseSphereWall(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    SphereBody* sphere = reinterpret_cast<SphereBody*>(lhs);
    WallBody*   wall   = reinterpret_cast<WallBody*>  (rhs);

    sphere->velocity -= wall->normal * (2.f * DotProduct(wall->normal, sphere->velocity));
}

void CollisionResponseBoxWall(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
    
    BoxBody*  box  = reinterpret_cast<BoxBody*> (lhs);
    WallBody* wall = reinterpret_cast<WallBody*>(rhs);

    box->velocity -= wall->normal * (2.f * DotProduct(wall->normal, box->velocity));
}

void CollisionResponseWallWall(RigidBody* lhs, RigidBody* rhs, float collision_time) {
    assert(lhs != nullptr);
    assert(rhs != nullptr);
}
