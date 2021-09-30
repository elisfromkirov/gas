#ifndef __SHAPE_MANAGER_HPP__
#define __SHAPE_MANAGER_HPP__

#include <cassert>

#include "Molecule.hpp"
#include "RayTracer.hpp"
#include "Scene.hpp"

class MoleculeManager {
public:
    MoleculeManager(RayTracer* ray_tracer, Scene* scene);
    ~MoleculeManager();

    void AddMolecule(IMolecule* molecule);

    void DrawMolecules() const;

private:
    std::list<IMolecule*> molecules_;

    RayTracer* ray_tracer_;
    Scene*     scene_;
};

#endif // __SHAPE_MANAGER_HPP__
