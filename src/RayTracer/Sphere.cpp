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

    float t1 = - b - sqrt(d)/a;
    float t2 = - b + sqrt(d)/a;

    if (0.f < t1 && t1 < 1.f) {
        *t = t2; 
    } else {
        *t = t1;
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
