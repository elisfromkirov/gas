#include <math.h>
#include <cassert>

#include "Primitive.hpp"

Sphere::Sphere(const Vector3<float>& center, float radius, 
               const Color& color, const Material& material)
    : center_(center), radius_(radius), color_(color), material_(material) {}

Sphere::~Sphere() {}

bool Sphere::RayIntersect(const Ray& ray, float* t) const {
    assert(t);

    // vector from ray's origin to Sphere's center
    Vector3<float> origin_center = ray.origin - center_;

    float a = DotProduct(ray.direction, ray.direction);
    float b = DotProduct(origin_center, ray.direction);
    float c = DotProduct(origin_center, origin_center) - radius_ * radius_;
    float d = b * b - a * c;

    if (d < 0.0f) {
        return false;
    }

    *t = (- b - sqrt(d)/a);
    return true;
}

Vector3<float> Sphere::GetNormal(const Vector3<float>& point) const {
    return Normalize(point - center_);
}

const Color& Sphere::GetColor() const {
    return color_;
}

const Material& Sphere::GetMaterial() const {
    return material_;
}

const Vector3<float>& Sphere::GetCenter() const {
    return center_;
}

void Sphere::SetCenter(const Vector3<float>& center) {
    center_ = center;
}
