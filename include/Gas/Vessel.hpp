#ifndef __VESSEL_HPP__
#define __VESSEL_HPP__

#include "GraphicsComponent.hpp"
#include "IGraphicsEntity.hpp"
#include "IPhysicsEntity.hpp"
#include "PhysicsComponent.hpp"

class Vessel : public IGraphicsEntity {
public:
    Vessel();
    ~Vessel();

    virtual IGraphicsComponent* GetGraphicsComponent() override;

private:
    VesselGraphicsComponent graphics_component_;
};

#endif // __VESSEL_HPP__
