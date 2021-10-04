#include "MoleculeManager.hpp"

MoleculeManager::MoleculeManager(RayTracer* ray_tracer, Scene* scene, PhysicsEngine* physics_engine)
    : ray_tracer_{ray_tracer}, scene_{scene}, physics_engine_{physics_engine} {}

MoleculeManager::~MoleculeManager() {
    for (auto molecule : molecules_) {
        delete molecule;
    }
    delete vessel_;
}

void MoleculeManager::AddMolecule(IMolecule* molecule) {
    assert(molecule != nullptr);

    molecules_.push_back(molecule);
    molecule->GetGraphicsComponent()->RegisterOnScene(scene_);
    molecule->GetPhysicsComponent()->RegisterOnPhysicsEngine(physics_engine_);
}

void MoleculeManager::AddVessel(Vessel* vessel) {
    assert(vessel != nullptr);

    vessel_ = vessel;
    vessel_->GetGraphicsComponent()->RegisterOnScene(scene_);
}

void MoleculeManager::DrawMolecules() {
    ray_tracer_->Trace(scene_);
}

void MoleculeManager::MoveMolecules(float delta_time) {
    physics_engine_->SimulatePhysics(delta_time);
}
