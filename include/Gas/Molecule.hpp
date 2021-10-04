#ifndef __MOLECULE_HPP__
#define __MOLECULE_HPP__

#include "GraphicsComponent.hpp"
#include "IGraphicsEntity.hpp"
#include "IPhysicsEntity.hpp"
#include "PhysicsComponent.hpp"

class IMolecule : public IPhysicsEntity, public IGraphicsEntity {};

class SphereMolecule : public IMolecule {
public:
    SphereMolecule(const Vector3<float>& center, float radius, 
                   const Vector3<float>& velocity, const Material* material);
    virtual ~SphereMolecule() override;

    virtual IGraphicsComponent* GetGraphicsComponent() override;

    virtual IPhysicsComponent* GetPhysicsComponent() override;

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    SphereGraphicsComponent graphics_component_;
    SpherePhysicsComponent physics_component_;
};

#endif // __MOLECULE_HPP__
