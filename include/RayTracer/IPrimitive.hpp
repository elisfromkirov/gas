#ifndef __I_PRIMITIVE_HPP__
#define __I_PRIMITIVE_HPP__

#include "Ray.hpp"
#include "Material.hpp"
#include "Vector3.hpp"

class IPrimitive {
public:
    virtual ~IPrimitive() = default;

    virtual bool RayIntersect(const Ray& ray, float* t) const = 0;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const = 0;

    virtual const Material* GetMaterial() const = 0;
};

#endif // __I_PRIMITVES_HPP__
