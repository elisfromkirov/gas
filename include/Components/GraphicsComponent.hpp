#ifndef __GRAPHIS_COMPONENT_HPP__
#define __GRAPHIS_COMPONENT_HPP__

#include <cassert>
#include <cstdint>

#include "Sphere.hpp"
#include "Scene.hpp"
#include "Triangle.hpp"

class IGraphicsComponent {
public:
    virtual ~IGraphicsComponent() = default;

    virtual void RegisterOnScene(Scene* scene) = 0;
};

class SphereGraphicsComponent : public IGraphicsComponent {
public:
    SphereGraphicsComponent(const Vector3<float>& center, float radius, const Material* material);
    virtual ~SphereGraphicsComponent() override = default;

    virtual void RegisterOnScene(Scene* scene) override;

private:
    Sphere sphere_;
};

#endif // __GRAPHIS_COMPONENT_HPP__
