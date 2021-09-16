#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "IShape.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"

class Sphere : public IShape {
public:
    Sphere(const Vector3<float>& center, float radius, const Color& color, const Material& material);

    virtual ~Sphere() override;

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Color& GetColor() const override;

    virtual const Material& GetMaterial() const override;

private:
    Vector3<float> center_;
    float          radius_;

    Color          color_;
    Material       material_;
};

#endif // __SPHERE_HPP__
