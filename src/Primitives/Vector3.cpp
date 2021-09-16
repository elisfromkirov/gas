#include <math.h>
#include <cfloat>

#include "Vector3.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

float GetLength(const Vector3<float>& vector) {
    return sqrtf(DotProduct(vector, vector));
}

Vector3<float> Normalize(const Vector3<float>& vector) {
    float length = GetLength(vector);

    if (IsEqual(length, 0.0f) && IsEqual(length, 1.0f)) {
        return vector;
    }

    return Vector3<float>{vector.x / length, vector.y / length, vector.z / length};
}
