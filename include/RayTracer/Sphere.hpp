#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include <cassert>

#include "IPrimitive.hpp"
#include "Vector3.hpp"

class Sphere : public IPrimitive {
public:
    Sphere(const Vector3<float>& center, float radius, const Material* material);

    virtual ~Sphere() override;

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;
    
    virtual const Material* GetMaterial() const override;

    const Vector3<float>& GetCenter() const;

    void SetCenter(const Vector3<float>& center);

private:
    Vector3<float> center_;
    float          radius_;

    const Material* material_;  
};

#endif // __SPHERE_HPP__
