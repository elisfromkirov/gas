#ifndef __ISHAPE_HPP__
#define __ISHAPE_HPP__

#include "Color.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"

class IShape {
public:
    virtual ~IShape() {}

    virtual bool RayIntersect(const Ray& ray, float* t) const = 0;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const = 0;

    virtual const Color& GetColor() const = 0;

    virtual const Material& GetMaterial() const = 0;
};

#endif // __ISHAPE_HPP__
