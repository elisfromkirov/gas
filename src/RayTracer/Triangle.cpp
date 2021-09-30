#include "Triangle.hpp"

Triangle::Triangle(const Vector3<float>& a, const Vector3<float>& b,
                   const Vector3<float>& c, const Material* material)
    : vertices_{a, b, c}, material_{material} {}

Triangle::~Triangle() {}

bool Triangle::RayIntersect(const Ray& ray, float* t) const {
    assert(t != nullptr);
}

Vector3<float> Triangle::GetNormal(const Vector3<float>& point) const {
    return CrossProduct(vertices_[0] - vertices_[1], vertices_[0] - vertices_[2]);
}

const Material* Triangle::GetMaterial() const {
    return material_;
}
