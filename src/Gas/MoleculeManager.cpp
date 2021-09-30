#include "MoleculeManager.hpp"

MoleculeManager::MoleculeManager(RayTracer* ray_tracer, Scene* scene)
    : ray_tracer_{ray_tracer}, scene_{scene} {}

MoleculeManager::~MoleculeManager() {
    for (auto molecule : molecules_) {
        delete molecule;
    }
}

void MoleculeManager::AddMolecule(IMolecule* molecule) {
    assert(molecule != nullptr);

    molecules_.push_back(molecule);
    scene_->AddPrimitive(molecule->GetGraphicsComponent());
}

void MoleculeManager::DrawMolecules() const {
    ray_tracer_->TraceScene(scene_);
}
