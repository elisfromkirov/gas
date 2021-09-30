#include "Triangle.hpp"

#include <stdio.h>

Triangle::Triangle(const Vector3<float>& p1, const Vector3<float>& p2,
             const Vector3<float>& p3, const Material* material)
    : points_{p1, p2, p3}, normal_{Normalize(CrossProduct(p2 - p1, p3 - p1))},
      sides_{p2 - p1, p3 - p1}, equation_matrix_{}, material_{material} {
    equation_matrix_[0][0] = DotProduct(sides_[1], sides_[1]);
    equation_matrix_[0][1] = DotProduct(sides_[0], sides_[1]) * (-1.f);
    equation_matrix_[1][0] = DotProduct(sides_[0], sides_[1]) * (-1.f);
    equation_matrix_[1][1] = DotProduct(sides_[0], sides_[0]);

    float determinant = Determinant(equation_matrix_);

    equation_matrix_ *= (1.f/determinant);
}

Triangle::~Triangle() {}

bool Triangle::RayIntersect(const Ray& ray, float* t) const {
    assert(t != nullptr);

    // intersection point = ray.origin + param * ray.direction
    float param = DotProduct(normal_, ray.origin - points_[0]) / DotProduct(normal_, ray.direction);

    // intersection point of ray and triangle's surface
    Vector3<float> intersection_point{ray.origin + ray.direction * param};

    // check that point is inside triangle    
    Vector2<float> w{equation_matrix_ * Vector2<float>{
        DotProduct((intersection_point - points_[0]), sides_[0]),
        DotProduct((intersection_point - points_[0]), sides_[1])}};

    *t = param;
    return (0.f < w.x) && (0.f < w.y) && (w.x + w.y < 1.f);
}

Vector3<float> Triangle::GetNormal(const Vector3<float>& point) const {
    return normal_;    
}

const Material* Triangle::GetMaterial() const {
    return material_;
}
