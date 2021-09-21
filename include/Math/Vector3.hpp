#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

template <typename T>
struct Vector3 {
    Vector3();

    Vector3(const T& x, const T& y, const T& z);

    Vector3(const Vector3& other);

    ~Vector3();

    Vector3& operator=(const Vector3& other);

    Vector3& operator+=(const Vector3& rhs);

    Vector3& operator-=(const Vector3& rhs);

    Vector3& operator*=(const T& rhs);

    T x;
    T y;
    T z;
};

template <typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Vector3<T> operator*(const Vector3<T>& lhs, const T& rhs);

template <typename T>
T DotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs);

float GetLength(const Vector3<float>& vector);

Vector3<float> Normalize(const Vector3<float>& vector);

// -------------------------------------------------------------------------- //

template <typename T>
Vector3<T>::Vector3() : x{}, y{}, z{} {}

template <typename T>
Vector3<T>::Vector3(const T& x, const T& y, const T& z) : x{x}, y{y}, z{z} {}

template <typename T>
Vector3<T>::Vector3(const Vector3& other) : x{other.x}, y{other.y}, z{other.z} {}

template <typename T>
Vector3<T>::~Vector3() {}

template <typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3& other) {
    if (this == &other) {
        return *this;
    }

    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(const T& rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;

    return *this;
}

template <typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs) {
    Vector3<T> result(lhs);
    result += rhs;
    return result;
}

template <typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs) {
    Vector3<T> result(lhs);
    result -= rhs;
    return result;
}

template <typename T>
Vector3<T> operator*(const Vector3<T>& lhs, const T& rhs) {
    Vector3<T> result(lhs);
    result *= rhs;
    return result;
}

template <typename T>
T DotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float GetLength(const Vector3<float>& vector);

Vector3<float> Normalize(const Vector3<float>& vector);

#endif // __VECTOR3_HPP__
