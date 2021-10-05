#include "Scene.hpp"
#include "Vessel.hpp"
#include "PhysicsEngine.hpp"

Material Vessel::wall{Color{0.0, 0.0, 0.0},
                      Color{0.2, 0.2, 0.2},
                      Color{0.2, 0.2, 0.2},
                      200};

Vessel::Vessel()
    : far_        {      Vector3<float>{ 1.0,  0.0,  0.0}, Vector3<float>{-1.0,  0.0,  0.0}, &wall},
      left_       {      Vector3<float>{ 0.0,  1.0,  0.0}, Vector3<float>{ 0.0, -1.0,  0.0}, &wall},
      right_      {      Vector3<float>{ 0.0, -1.0,  0.0}, Vector3<float>{ 0.0,  1.0,  0.0}, &wall},
      top_        {      Vector3<float>{ 0.0,  0.0, -1.0}, Vector3<float>{ 0.0,  0.0,  1.0}, &wall},
      bottom_     {      Vector3<float>{ 0.0,  0.0,  1.0}, Vector3<float>{ 0.0,  0.0, -1.0}, &wall},
      far_wall_   {this, Vector3<float>{ 1.0,  0.0,  0.0}, Vector3<float>{-1.f,  0.f,  0.0}       },
      near_wall_  {this, Vector3<float>{-1.0,  0.0,  0.0}, Vector3<float>{ 1.f,  0.f,  0.0}       },
      left_wall_  {this, Vector3<float>{ 0.0,  1.0,  0.0}, Vector3<float>{ 0.f, -1.f,  0.0}       },
      right_wall_ {this, Vector3<float>{ 0.0, -1.0,  0.0}, Vector3<float>{ 0.f,  1.f,  0.0}       },
      top_wall_   {this, Vector3<float>{ 0.0,  0.0, -1.0}, Vector3<float>{ 0.f,  0.f,  1.0}       },
      bottom_wall_{this, Vector3<float>{ 0.0,  0.0,  1.0}, Vector3<float>{ 0.f,  0.f, -1.0}       }
    {}

Vessel::~Vessel() {}

void Vessel::RegisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->RegisterPrimitive(&far_);
    scene->RegisterPrimitive(&left_);
    scene->RegisterPrimitive(&right_);
    scene->RegisterPrimitive(&top_);
    scene->RegisterPrimitive(&bottom_);
}

void Vessel::UnregisterOnScene(Scene* scene) {}

void Vessel::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->RegisterRigidBody(&near_wall_);
    physics_engine->RegisterRigidBody(&far_wall_);
    physics_engine->RegisterRigidBody(&left_wall_);
    physics_engine->RegisterRigidBody(&right_wall_);
    physics_engine->RegisterRigidBody(&top_wall_);
    physics_engine->RegisterRigidBody(&bottom_wall_);
}

void Vessel::UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) {}

void Vessel::Move(const Vector3<float>& displacement) {}

void Vessel::CollisionResponse(IPhysicsEntity* entity) {}
