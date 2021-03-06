#include "BoxMolecule.hpp"
#include "Scene.hpp"
#include "PhysicsEngine.hpp"

Material BoxMolecule::material{Color{0.0, 0.1, 0.0},
                               Color{0.0, 0.3, 0.2},
                               Color{0.1, 0.3, 0.3},
                               80};

BoxMolecule::BoxMolecule(const Vector3<float>& center, const Vector3<float>& size,
                         const Vector3<float>& velocity)
    : graphics_component_{center, size, &material},
      physics_component_{this, center, size, velocity, 1.0}
    {}

BoxMolecule::~BoxMolecule() {}

void BoxMolecule::RegisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->RegisterPrimitive(&graphics_component_);
}

void BoxMolecule::UnregisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->UnregisterPrimitive(&graphics_component_);
}

void BoxMolecule::RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->RegisterRigidBody(&physics_component_);
}

void BoxMolecule::UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) {
    assert(physics_engine != nullptr);

    physics_engine->UnregisterRigidBody(&physics_component_);
}

void BoxMolecule::Move(const Vector3<float>& displacement) {
    graphics_component_.SetCenter(graphics_component_.GetCenter() + displacement);
}
