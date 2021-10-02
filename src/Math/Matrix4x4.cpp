#include <math.h>
#include <cfloat>

#include "Matrix4x4.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

Vector3<float> operator*(const Matrix4x4<float>& lhs, const Vector3<float>& rhs) {
    float buffer[] = { lhs.m[0]  * rhs.x + lhs.m[1]  * rhs.y + lhs.m[2]  * rhs.z + lhs.m[3] ,
                       lhs.m[4]  * rhs.x + lhs.m[5]  * rhs.y + lhs.m[6]  * rhs.z + lhs.m[7] ,
                       lhs.m[8]  * rhs.x + lhs.m[9]  * rhs.y + lhs.m[10] * rhs.z + lhs.m[11],
                       lhs.m[12] * rhs.x + lhs.m[13] * rhs.y + lhs.m[14] * rhs.z + lhs.m[15] };

    assert(!IsEqual(buffer[3], 0.f));

    return Vector3<float>{buffer[0] / buffer[3], buffer[1] / buffer[3], buffer[2] / buffer[3]};
}
