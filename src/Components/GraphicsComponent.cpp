#include "GraphicsComponent.hpp"

SphereGraphicsComponent::SphereGraphicsComponent(
    const Vector3<float>& center, float radius, const Material* material)
    : sphere_{center, radius, material} {}

void SphereGraphicsComponent::RegisterOnScene(Scene* scene) {
    assert(scene);

    scene->RegisterPrimitive(&sphere_);
}
