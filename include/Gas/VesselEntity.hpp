#ifndef __VESSEL_ENTITY_HPP__
#define __VESSEL_ENTITY_HPP__

#include "IPhysicsEntity.hpp"
#include "Primitive.hpp"
#include "PhysicsComponent.hpp"

class VesselEntity : public IPhysicsEntity {
public:
    VesselEntity(BoxPhysicsComponent* near, BoxPhysicsComponent* far,
                 BoxPhysicsComponent* left, BoxPhysicsComponent* right,
                 BoxPhysicsComponent* top,  BoxPhysicsComponent* bottom);
    ~VesselEntity();

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    BoxPhysicsComponent* near_;
    BoxPhysicsComponent* far_;
    BoxPhysicsComponent* left_; 
    BoxPhysicsComponent* right_;
    BoxPhysicsComponent* top_;
    BoxPhysicsComponent* bottom_;

};

#endif // __VESSEL_ENTITY_HPP__
