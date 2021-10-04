#ifndef __VESSEL_HPP__
#define __VESSEL_HPP__

#include "GraphicsComponent.hpp"
#include "IGraphicsEntity.hpp"
#include "IPhysicsEntity.hpp"
#include "PhysicsComponent.hpp"

class Vessel : public IGraphicsEntity, public IPhysicsEntity {
public:
    Vessel();
    ~Vessel();

    virtual IGraphicsComponent* GetGraphicsComponent() override;

    virtual IPhysicsComponent* GetPhysicsComponent() override;

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    VesselGraphicsComponent graphics_component_;
    VesselPhysicsComponent physics_component_;
};

#endif // __VESSEL_HPP__
