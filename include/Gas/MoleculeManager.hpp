#ifndef __SHAPE_MANAGER_HPP__
#define __SHAPE_MANAGER_HPP__

#include <cassert>
#include <vector>

#include "IEventListener.hpp"
#include "IMolecule.hpp"
#include "Vessel.hpp"
#include "RayTracer.hpp"
#include "Scene.hpp"
#include "PhysicsEngine.hpp"
#include "PhysicsEvent.hpp"

class MoleculeManager : public IEventListener {
public:
    MoleculeManager(RayTracer* ray_tracer, Scene* scene, PhysicsEngine* physics_engine);
    ~MoleculeManager();

    virtual void OnEvent(const IEvent* event) override;

    void AddMolecule(IMolecule* molecule);
    void AddVessel(Vessel* vessel);

    void DrawMolecules();
    
    void SimulateMoleculesPhysics(float delta_time);

private:
    void OnCollisionEvent(const CollisionEvent* event);

private:
    struct Molecule {
        IMolecule*      pointer;
        IPhysicsEntity* physics_molecule;
    };
    std::vector<Molecule> molecules_;
    Vessel* vessel_;

    RayTracer*            ray_tracer_;
    Scene*                scene_;

    PhysicsEngine*        physics_engine_;
};

#endif // __SHAPE_MANAGER_HPP__
