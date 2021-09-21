#include <math.h>
#include <cfloat>

#include "Vector2.hpp"

static bool IsEqual(float lhs, float rhs) {
    return fabs(lhs - rhs) < FLT_EPSILON;
}

float GetLength(const Vector2<float>& vector) {
    return sqrtf(DotProduct(vector, vector));
}

Vector2<float> Normalize(const Vector2<float>& vector) {
    float length = GetLength(vector);

    if (IsEqual(length, 0.0f) && IsEqual(length, 1.0f)) {
        return vector;
    }

    return Vector2<float>{vector.x / length, vector.y / length};
}
