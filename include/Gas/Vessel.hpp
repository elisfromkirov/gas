#ifndef __VESSEL_HPP__
#define __VESSEL_HPP__

#include <cassert>

#include "IMolecule.hpp"
#include "RigidBody.hpp"
#include "Surface.hpp"

class Vessel : public IGraphicsEntity, public IPhysicsEntity {
private:
    static Material wall;

public:
    Vessel();
    virtual ~Vessel() override;

    virtual void RegisterOnScene(Scene* scene) override;
    virtual void UnregisterOnScene(Scene* scene) override;

    virtual void RegisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;
    virtual void UnregisterOnPhysicsEngine(PhysicsEngine* physics_engine) override;

    virtual void Move(const Vector3<float>& displacement) override;

    virtual void CollisionResponse(IPhysicsEntity* entity) override;

private:
    Surface far_;
    Surface left_;
    Surface right_;
    Surface top_;
    Surface bottom_;
      
    WallBody far_wall_;
    WallBody near_wall_;
    WallBody left_wall_;
    WallBody right_wall_;
    WallBody top_wall_;
    WallBody bottom_wall_;
};

#endif // __VESSEL_HPP__
