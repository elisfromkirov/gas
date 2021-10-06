#include "Scene.hpp"
#include "SphereMolecule.hpp"
#include "PhysicsEngine.hpp"

Material SphereMolecule::material{Color{0.1, 0.0, 0.0},
                                  Color{0.5, 0.0, 0.2},
                                  Color{0.5, 0.3, 0.0},
                                  300};

SphereMolecule::SphereMolecule(const Vector3<float>& center,
                               float radius,
                               const Vector3<float>& velocity)
    : graphics_component_{center, radius, &material},
      physics_component_{this, center, radius, velocity, 1.0}
    {}

SphereMolecule::~SphereMolecule() {}

void SphereMolecule::RegisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->RegisterPrimitive(&graphics_component_);
}

void SphereMolecule::UnregisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->UnregisterPrimitive(&graphics_component_);
}

void SphereMolecule::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->RegisterRigidBody(&physics_component_);
}

void SphereMolecule::UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->UnregisterRigidBody(&physics_component_);
}

void SphereMolecule::Move(const Vector3<float>& displacement) {
    graphics_component_.SetCenter(graphics_component_.GetCenter() + displacement);
}
