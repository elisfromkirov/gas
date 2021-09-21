#ifndef __MOLECULE_ENTITY_HPP__
#define __MOLECULE_ENTITY_HPP__

#include "IPhysicsEntity.hpp"
#include "Primitive.hpp"
#include "PhysicsComponent.hpp"

class MoleculeEntity : public IPhysicsEntity {
public:
    MoleculeEntity(Sphere* sphere, SpherePhysicsComponent* physics_component);
    ~MoleculeEntity();

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    Sphere*                 sphere_;
    SpherePhysicsComponent* physics_component_;
};

#endif // __MOLECULE_ENTITY_HPP__
