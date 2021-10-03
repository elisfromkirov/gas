#include <float.h>
#include <math.h>
#include <stdio.h>

#include "Matrix4x4.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

Vector3<float> TransformPoint(const Matrix4x4<float>& lhs, const Vector3<float>& rhs) {
    float w = lhs[3][0] * rhs.x + lhs[3][1] * rhs.y + lhs[3][2] * rhs.z + lhs[3][3];
    assert(!IsEqual(w, 0.f));
    
    return Vector3<float>{
        (lhs[0][0] * rhs.x + lhs[0][1] * rhs.y + lhs[0][2] * rhs.z + lhs[0][3]) / w,
        (lhs[1][0] * rhs.x + lhs[1][1] * rhs.y + lhs[1][2] * rhs.z + lhs[1][3]) / w,
        (lhs[2][0] * rhs.x + lhs[2][1] * rhs.y + lhs[2][2] * rhs.z + lhs[2][3]) / w };
}

Vector3<float> TransformVector(const Matrix4x4<float>& lhs, const Vector3<float>& rhs) {
    return Vector3<float>{
        lhs[0][0] * rhs.x + lhs[0][1] * rhs.y + lhs[0][2] * rhs.z,
        lhs[1][0] * rhs.x + lhs[1][1] * rhs.y + lhs[1][2] * rhs.z,
        lhs[2][0] * rhs.x + lhs[2][1] * rhs.y + lhs[2][2] * rhs.z };
}
