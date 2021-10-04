#include <float.h>
#include <math.h>

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

#include "Surface.hpp"

Surface::Surface(
    const Vector3<float>& normal, const Vector3<float>& point, const Material* material) 
    : normal_{Normalize(normal), Normalize(normal)}, point_{point, point}, material_{material} {}

Surface::~Surface() {}

bool Surface::RayIntersect(const Ray& ray, float* t) const {
    float product = DotProduct(normal_.camera_space, ray.direction);
    if (IsEqual(product, 0.f)) {
        return false;
    }

    float s = DotProduct(normal_.camera_space, point_.camera_space - ray.origin)/product;
    if (s < 0.f) {
        return false;
    }

    *t = s;
    return true;
}

Vector3<float> Surface::GetNormal(const Vector3<float>& point) const {
    return normal_.camera_space;
}

const Material* Surface::GetMaterial() const {
    return material_;
}

void Surface::TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) {
    normal_.camera_space = TransformVector(veiw_matrix, normal_.world_space);
    point_.camera_space  = TransformPoint (veiw_matrix, point_.world_space);
}
