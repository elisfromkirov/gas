#include "GraphicsComponent.hpp"

SphereGraphicsComponent::SphereGraphicsComponent(
    const Vector3<float>& center, float radius, const Material* material)
    : sphere_{center, radius, material} {}

SphereGraphicsComponent::~SphereGraphicsComponent() {}

void SphereGraphicsComponent::RegisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->RegisterPrimitive(&sphere_);
}

void SphereGraphicsComponent::Move(const Vector3<float>& displacement) {
    sphere_.SetCenter(sphere_.GetCenter() + displacement);
}

Material VesselGraphicsComponent::far_material {Color{0.1, 0.1, 0.1}, Color{0.1, 0.1, 0.1}, 200};
Material VesselGraphicsComponent::wall_material{Color{0.2, 0.2, 0.2}, Color{0.2, 0.2, 0.2}, 200};

VesselGraphicsComponent::VesselGraphicsComponent()
    : far_   {Vector3<float>{1.f,  0.f,  0.f}, Vector3<float>{-1.f,  0.f,  0.f}, &far_material},
      left_  {Vector3<float>{0.f,  1.f,  0.f}, Vector3<float>{ 0.f, -1.f,  0.f}, &wall_material},
      right_ {Vector3<float>{0.f, -1.f,  0.f}, Vector3<float>{ 0.f,  1.f,  0.f}, &wall_material},
      top_   {Vector3<float>{0.f,  0.f, -1.f}, Vector3<float>{ 0.f,  0.f,  1.f}, &wall_material},
      bottom_{Vector3<float>{0.f,  0.f,  1.f}, Vector3<float>{ 0.f,  0.f, -1.f}, &wall_material} {}

VesselGraphicsComponent::~VesselGraphicsComponent() {}

void VesselGraphicsComponent::RegisterOnScene(Scene* scene) {
    assert(scene != nullptr);

    scene->RegisterPrimitive(&far_);
    scene->RegisterPrimitive(&left_);
    scene->RegisterPrimitive(&right_);
    scene->RegisterPrimitive(&top_);
    scene->RegisterPrimitive(&bottom_);
}
