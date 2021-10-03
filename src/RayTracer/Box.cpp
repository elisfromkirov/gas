#include <float.h>
#include <math.h>

#include <stdio.h>

#include "Box.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

Box::Box(const Vector3<float>& center, const Vector3<float>& size, const Material* material) 
    : center_{center}, size_{size}, material_{material} { 
    surfaces_[0].world_space.normal = Vector3<float>{ 1.f,  0.f,  0.f};
    surfaces_[1].world_space.normal = Vector3<float>{-1.f,  0.f,  0.f};
    surfaces_[2].world_space.normal = Vector3<float>{ 0.f,  1.f,  0.f};
    surfaces_[3].world_space.normal = Vector3<float>{ 0.f, -1.f,  0.f};
    surfaces_[4].world_space.normal = Vector3<float>{ 0.f,  0.f,  1.f};
    surfaces_[5].world_space.normal = Vector3<float>{ 0.f,  0.f, -1.f};

    surfaces_[0].world_space.point = Vector3<float>{center + size * 0.5f};
    surfaces_[1].world_space.point = Vector3<float>{center - size * 0.5f};
    surfaces_[2].world_space.point = Vector3<float>{center + size * 0.5f};
    surfaces_[3].world_space.point = Vector3<float>{center - size * 0.5f};
    surfaces_[4].world_space.point = Vector3<float>{center + size * 0.5f};
    surfaces_[5].world_space.point = Vector3<float>{center - size * 0.5f};
}

Box::~Box() {}

bool Box::RayIntersect(const Ray& ray, float* t) const {
    assert(t != nullptr);

    float min_t = FLT_MAX;
    bool intersected = false;

    uint32_t index = 0;

    for (uint32_t i = 0; i < kSurfaceCount; ++i) {
        float cur_t = FLT_MAX;
        if (BoxSideRayIntersect(i, ray, &cur_t)) {
            if (cur_t < min_t) {
                min_t = cur_t;
                intersected = true;
                index = i;
            }
        }
    }

    *t = min_t;
    return intersected;
}

Vector3<float> Box::GetNormal(const Vector3<float>& point) const {
    for (uint32_t i = 0; i < kSurfaceCount; ++i) {
        if (IsEqual(0.f, DotProduct(surfaces_[i].camera_space.normal,
                                    surfaces_[i].camera_space.point - point))) {
            return surfaces_[i].camera_space.normal;
        }
    }

    return Vector3<float>{};
}

const Material* Box::GetMaterial() const {
    return material_;
}

void Box::TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) {
    for (uint32_t i = 0; i < kSurfaceCount; ++i) {
        surfaces_[i].camera_space.normal = TransformVector(veiw_matrix,
                                                           surfaces_[i].world_space.normal);
        surfaces_[i].camera_space.point  = TransformPoint(veiw_matrix,
                                                          surfaces_[i].world_space.point);
    }
}

bool Box::BoxSideRayIntersect(uint32_t index, const Ray& ray, float* t) const {
    float p = DotProduct(surfaces_[index].camera_space.normal, 
                         surfaces_[index].camera_space.point - ray.origin) /
              DotProduct(surfaces_[index].camera_space.normal, ray.direction);

    Vector3<float> intersection_point{ray.origin + ray.direction * p};

    for (uint32_t i = 0; i < kSurfaceCount; ++i) {
        if (i != index) {
            float s = DotProduct(surfaces_[i].camera_space.normal, 
                                 surfaces_[i].camera_space.point - intersection_point);
            if (!(s > 0.f)) {
                return false;
            }
        }
    }
    
    *t = p;
    return true;
}
