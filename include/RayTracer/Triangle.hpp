#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include <cassert>

#include "IPrimitive.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix2x2.hpp"

class Triangle : public IPrimitive {
public:
    Triangle(const Vector3<float>& p1, const Vector3<float>& p2,
             const Vector3<float>& p3, const Material* material);

    virtual ~Triangle();

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Material* GetMaterial() const override;

private:
    Vector3<float> points_[3];
    Vector3<float> normal_;
    Vector3<float> sides_[2];
    Matrix2x2<float> equation_matrix_;

    const Material* material_;
};

#endif // __TRIANGLE_HPP__
