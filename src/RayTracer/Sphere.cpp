#include <math.h>

#include "Sphere.hpp"

Sphere::Sphere(const Vector3<float>& center, float radius, const Material* material)
    : center_{center, center}, radius_{radius, radius}, material_{material} {}

Sphere::~Sphere() {}

bool Sphere::RayIntersect(const Ray& ray, float* t) const {
    assert(t != nullptr);

    Vector3<float> origin_center = ray.origin - center_.camera_space;

    float a = DotProduct(ray.direction, ray.direction);
    float b = DotProduct(origin_center, ray.direction);
    float c = DotProduct(origin_center, origin_center) - radius_.camera_space * radius_.camera_space;
    float d = b * b - a * c;

    if (d < 0.0f) {
        return false;
    }

    float roots[] = {(-b - sqrt(d))/a, (-b + sqrt(d))/a};

    if (0.f < roots[0] && roots[0] < 1.f) {
        *t = roots[1];
    } else {
        *t = roots[0];
    }

    return true;
}

Vector3<float> Sphere::GetNormal(const Vector3<float>& point) const {
    return Normalize(point - center_.camera_space);
}

const Material* Sphere::GetMaterial() const {
    return material_;
}

void Sphere::TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) {
    center_.camera_space = TransformPoint(veiw_matrix, center_.world_space);
}

const Vector3<float>& Sphere::GetCenter() const {
    return center_.world_space;
}

void Sphere::SetCenter(const Vector3<float>& center) {
    center_.world_space = center;
}