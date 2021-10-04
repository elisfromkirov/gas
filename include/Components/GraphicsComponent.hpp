#ifndef __GRAPHIS_COMPONENT_HPP__
#define __GRAPHIS_COMPONENT_HPP__

#include <cassert>
#include <cstdint>

#include "Box.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Surface.hpp"

class IGraphicsComponent {
public:
    virtual ~IGraphicsComponent() {}

    virtual void RegisterOnScene(Scene* scene) = 0;
};

class SphereGraphicsComponent : public IGraphicsComponent {
public:
    SphereGraphicsComponent(const Vector3<float>& center, float radius, const Material* material);
    virtual ~SphereGraphicsComponent() override;

    virtual void RegisterOnScene(Scene* scene) override;

    void Move(const Vector3<float>& displacement);

private:
    Sphere sphere_;
};

class VesselGraphicsComponent : public IGraphicsComponent {
private:
    static Material far_material;
    static Material wall_material;

public:
    VesselGraphicsComponent();
    virtual ~VesselGraphicsComponent();

    virtual void RegisterOnScene(Scene* scene) override;

private:
    Surface far_;
    Surface left_;
    Surface right_;
    Surface top_;
    Surface bottom_;
};

#endif // __GRAPHIS_COMPONENT_HPP__
