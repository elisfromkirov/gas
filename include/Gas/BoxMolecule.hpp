#ifndef __BOX_MOLECULE_HPP__
#define __BOX_MOLECULE_HPP__

#include <cassert>

#include "Box.hpp"
#include "IMolecule.hpp"
#include "RigidBody.hpp"

class BoxMolecule : public IMolecule {
private:
    static Material material;

public:
    BoxMolecule(const Vector3<float>& center, const Vector3<float>& size,
                const Vector3<float>& velocity);
    virtual ~BoxMolecule() override;

    virtual void RegisterOnScene(Scene* scene) override;
    virtual void UnregisterOnScene(Scene* scene) override;

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;
    virtual void UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;

    virtual void Move(const Vector3<float>& displacement) override;

private:
    Box     graphics_component_;
    BoxBody physics_component_;
};

#endif // __BOX_MOLECULE_HPP__
