#ifndef __MOLECULE_HPP__
#define __MOLECULE_HPP__

#include "IMolecule.hpp"
#include "RigidBody.hpp"
#include "Sphere.hpp"

class SphereMolecule : public IMolecule {
private:
    static Material material;    

public:
    SphereMolecule(const Vector3<float>& center, float radius, const Vector3<float>& velocity);
    virtual ~SphereMolecule() override;

    virtual void RegisterOnScene(Scene* scene) override;
    virtual void UnregisterOnScene(Scene* scene) override;

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;
    virtual void UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    Sphere     graphics_component_;
    SphereBody physics_component_;
};

#endif // __MOLECULE_HPP__
