#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include <cassert>

#include "IPrimitive.hpp"

class Triangle : public IPrimitive {
public:
    Triangle(const Vector3<float>& a, const Vector3<float>& b,
             const Vector3<float>& c, const Material* material);

    virtual ~Triangle();

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Material* GetMaterial() const override;

private:
    Vector3<float> vertices_[3];
    
    const Material* material_;
};

#endif // __TRIANGLE_HPP__
