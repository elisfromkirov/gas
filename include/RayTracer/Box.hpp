#ifndef __BOX_HPP__
#define __BOX_HPP__

#include <cassert>
#include <cstdint>

#include "IPrimitive.hpp"
#include "SpaceDepenedentData.hpp"
#include "Matrix4x4.hpp"
#include "Vector3.hpp"

class Box : public IPrimitive {
private:
    static const uint32_t kSurfaceCount{6};

public:
    Box(const Vector3<float>& center, const Vector3<float>& size, const Material* material);
    virtual ~Box() override;

    virtual bool RayIntersect(const Ray& ray, float* t) const override;

    virtual Vector3<float> GetNormal(const Vector3<float>& point) const override;

    virtual const Material* GetMaterial() const override;

    virtual void TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) override;

private:
    bool BoxSideRayIntersect(uint32_t index, const Ray& ray, float* t) const;

private:
    Vector3<float> center_;
    Vector3<float> size_;

    struct Surface {
        Vector3<float> normal;
        Vector3<float> point;
    };
    SpaceDependentData<Surface> surfaces_[kSurfaceCount];

    const Material* material_;
};

#endif // __BOX_HPP__
