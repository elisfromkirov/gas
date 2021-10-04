#ifndef __SHAPE_MANAGER_HPP__
#define __SHAPE_MANAGER_HPP__

#include <cassert>

#include "Molecule.hpp"
#include "RayTracer.hpp"
#include "Scene.hpp"
#include "PhysicsEngine.hpp"
#include "Vessel.hpp"

class MoleculeManager {
public:
    MoleculeManager(RayTracer* ray_tracer, Scene* scene, PhysicsEngine* physics_engine);
    ~MoleculeManager();

    void AddMolecule(IMolecule* molecule);
    void AddVessel(Vessel* vessel);

    void DrawMolecules();
    
    void MoveMolecules();

private:
    std::list<IMolecule*> molecules_;
    Vessel* vessel_;

    RayTracer*            ray_tracer_;
    Scene*                scene_;

    PhysicsEngine*        physics_engine_;
};

#endif // __SHAPE_MANAGER_HPP__
