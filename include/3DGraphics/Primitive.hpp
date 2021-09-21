#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include "Ray.hpp"
#include "Color.hpp"
#include "Material.hpp"
#include "Vector3.hpp"

class IPrimitive {
public:
    virtual ~IPrimitive() {}

    virtual bool RayIntersect(const Ray& ray, float* t) const = 0;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const = 0;

    virtual const Color& GetColor() const = 0;

    virtual const Material& GetMaterial() const = 0;
};

class Sphere : public IPrimitive {
public:
    Sphere(const Vector3<float>& center, float radius, const Color& color, const Material& material);
    virtual ~Sphere() override;

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Color& GetColor() const override;
    
    virtual const Material& GetMaterial() const override;

    const Vector3<float>& GetCenter() const;

    void SetCenter(const Vector3<float>& center);

private:
    Vector3<float> center_;
    float          radius_;

    Color          color_;
    Material       material_;
};

#endif // __PRIMITVES_HPP__
