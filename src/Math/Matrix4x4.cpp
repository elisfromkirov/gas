#include <float.h>
#include <math.h>
#include <stdio.h>

#include "Matrix4x4.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

Vector3<float> operator*(const Matrix4x4<float>& lhs, const Vector3<float>& rhs) {
    float buffer[] = { lhs[0][0] * rhs.x + lhs[0][1] * rhs.y + lhs[0][2] * rhs.z + lhs[0][3],
                       lhs[1][0] * rhs.x + lhs[1][1] * rhs.y + lhs[1][2] * rhs.z + lhs[1][3],
                       lhs[2][0] * rhs.x + lhs[2][1] * rhs.y + lhs[2][2] * rhs.z + lhs[2][3],
                       lhs[3][0] * rhs.x + lhs[3][1] * rhs.y + lhs[3][2] * rhs.z + lhs[3][3] };

    if (IsEqual(buffer[3], 0.f)) {
        printf("vector: %lg %lg %lg\n", rhs.x, rhs.y, rhs.z);
        printf("buffer: %lg %lg %lg %lg\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        assert(0);
    }

    return Vector3<float>{buffer[0] / buffer[3], buffer[1] / buffer[3], buffer[2] / buffer[3]};
}
