#ifndef __SURFACE_HPP__
#define __SURFACE_HPP__

#include "IPrimitive.hpp"
#include "Matrix4x4.hpp"
#include "SpaceDepenedentData.hpp"
#include "Vector3.hpp"

class Surface : public IPrimitive {
public:
    Surface(const Vector3<float>& normal, const Vector3<float>& point, const Material* material);

    virtual ~Surface() override;

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Material* GetMaterial() const override;

    virtual void TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) override;

private:
    SpaceDependentData<Vector3<float>> normal_;
    SpaceDependentData<Vector3<float>> point_;

    const Material* material_;
};

#endif // __SURFACE_HPP__
