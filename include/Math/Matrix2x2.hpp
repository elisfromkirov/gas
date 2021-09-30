#ifndef __MATRIX2X2_HPP__
#define __MATRIX2X2_HPP__

#include <cassert>

template <typename T>
struct Matrix2x2 {
    Matrix2x2();    

    Matrix2x2(const T& m00, const T& m01, const T& m10, const T& m11);

    Matrix2x2(const Matrix2x2& other);

    ~Matrix2x2();

    Matrix2x2& operator=(const Matrix2x2& other);

    Matrix2x2& operator+=(const Matrix2x2& rhs);

    Matrix2x2& operator-=(const Matrix2x2& rhs);

    Matrix2x2& operator*=(const Matrix2x2& rhs);

    Matrix2x2& operator*=(T rhs);

    T* operator[](uint32_t i);

    const T* operator[](uint32_t i) const;

    T m[4];
};

template <typename T>
Matrix2x2<T> operator+(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs);

template <typename T>
Matrix2x2<T> operator-(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs);

template <typename T>
Matrix2x2<T> operator*(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs);

template <typename T>
Matrix2x2<T> operator*(const Matrix2x2<T>& lhs, T rhs);

template <typename T>
Vector2<T> operator*(const Matrix2x2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
T Determinant(const Matrix2x2<T>& matrix);

// -------------------------------------------------------------------------- //

template <typename T>
Matrix2x2<T>::Matrix2x2() : m{} {}

template <typename T>
Matrix2x2<T>::Matrix2x2(const T& m00, const T& m01, const T& m10, const T& m11)
    : m{m00, m01, m10, m11} {}

template <typename T>
Matrix2x2<T>::Matrix2x2(const Matrix2x2& other)
    : m{other.m[0], other.m[1], other.m[2], other.m[3]} {}

template <typename T>
Matrix2x2<T>::~Matrix2x2() {}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator=(const Matrix2x2& other) {
    if (this == &other) {
        return *this;
    }

    m = {other.m[0], other.m[1], other.m[2], other.m[3]};

    return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator+=(const Matrix2x2& rhs) {
    m[0] += rhs.m[0];
    m[1] += rhs.m[1];
    m[2] += rhs.m[2];
    m[3] += rhs.m[3];

    return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator-=(const Matrix2x2& rhs) {
    m[0] -= rhs.m[0];
    m[1] -= rhs.m[1];
    m[2] -= rhs.m[2];
    m[3] -= rhs.m[3];

    return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator*=(const Matrix2x2& rhs) {
    float temp[] = {m[0], m[1], m[2], m[3]};

    m[0] = {temp[0]*rhs.m[0] + temp[1]*rhs.m[2]};
    m[1] = {temp[0]*rhs.m[1] + temp[1]*rhs.m[3]};
    m[2] = {temp[2]*rhs.m[0] + temp[3]*rhs.m[2]};
    m[3] = {temp[2]*rhs.m[1] + temp[3]*rhs.m[3]};

    return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator*=(T rhs) {
    m[0] *= rhs;
    m[1] *= rhs;
    m[2] *= rhs;
    m[3] *= rhs;

    return *this;
}

template <typename T>
T* Matrix2x2<T>::operator[](uint32_t i) {
    assert(i < 2);
    
    return &m[i*2];
}

template <typename T>
const T* Matrix2x2<T>::operator[](uint32_t i) const {
    assert(i < 2);
    
    return &m[i*2];
}

template <typename T>
Matrix2x2<T> operator+(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs) {
    Matrix2x2<T> result(lhs);
    result += rhs;
    return result;
}

template <typename T>
Matrix2x2<T> operator-(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs) {
    Matrix2x2<T> result(lhs);
    result -= rhs;
    return result;
}

template <typename T>
Matrix2x2<T> operator*(const Matrix2x2<T>& lhs, const Matrix2x2<T>& rhs) {
    Matrix2x2<T> result(lhs);
    result *= rhs;
    return result;
}

template <typename T>
Matrix2x2<T> operator*(const Matrix2x2<T>& lhs, T rhs) {
    Matrix2x2<T> result(lhs);
    result *= rhs;
    return result;
}

template <typename T>
Vector2<T> operator*(const Matrix2x2<T>& lhs, const Vector2<T>& rhs) {
    return Vector2<T>{lhs.m[0]*rhs.x + lhs.m[1]*rhs.y, lhs.m[2]*rhs.x + lhs.m[3]*rhs.y};
}

template <typename T>
T Determinant(const Matrix2x2<T>& matrix) {
    return T{matrix.m[0] * matrix.m[3] - matrix.m[1] * matrix.m[2]};
}

#endif // __MATRIX2X2_HPP__
