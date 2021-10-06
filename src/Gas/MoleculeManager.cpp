#include "MoleculeManager.hpp"

MoleculeManager::MoleculeManager(RayTracer* ray_tracer, Scene* scene, PhysicsEngine* physics_engine)
    : ray_tracer_{ray_tracer}, scene_{scene}, physics_engine_{physics_engine} {}

MoleculeManager::~MoleculeManager() {
    for (uint32_t i = 0; i < molecules_.size(); ++i) {
        delete molecules_.at(i).pointer;
    }
    delete vessel_;
}

void MoleculeManager::OnEvent(const IEvent* event) {
    assert(event != nullptr);

    if (event->GetCategory() == kCollisionEventCategory) {
        OnCollisionEvent(reinterpret_cast<const CollisionEvent*>(event));
    }
}

void MoleculeManager::OnCollisionEvent(const CollisionEvent* event) {
    assert(event != nullptr);
    
    IPhysicsEntity* first_molecule  = event->GetFirstEntity();
    IPhysicsEntity* second_molecule = event->GetSecondEntity();

    uint32_t first  = molecules_.size();
    uint32_t second = molecules_.size();
    for (uint32_t i = 0; i < molecules_.size(); ++i) {
        if (molecules_.at(i).physics_molecule == first_molecule) {
            first = i;
        }
        if (molecules_.at(i).physics_molecule == second_molecule) {
            second = i;
        }
    }
    if (first == molecules_.size() || second == molecules_.size()) {
        return;
    }

    printf("MOLECULES CHEMISTRY\n");
}

void MoleculeManager::AddMolecule(IMolecule* molecule) {
    assert(molecule != nullptr);

    molecules_.push_back(Molecule{molecule, molecule});
    molecule->RegisterOnScene(scene_);
    molecule->RegisterOnPhysicsEngine(physics_engine_);
}

void MoleculeManager::AddVessel(Vessel* vessel) {
    assert(vessel != nullptr);

    vessel_ = vessel;
    vessel_->RegisterOnScene(scene_);
    vessel_->RegisterOnPhysicsEngine(physics_engine_);
}

void MoleculeManager::DrawMolecules() {
    ray_tracer_->Trace(scene_);
}

void MoleculeManager::SimulateMoleculesPhysics(float delta_time) {
    physics_engine_->SimulatePhysics(delta_time);
}
