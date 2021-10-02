#ifndef __MATRIX4X4_HPP__
#define __MATRIX4X4_HPP__

#include <algorithm>
#include <cassert>
#include <cstdint>

#include "Vector3.hpp"

template <typename T>
struct Matrix4x4 {
    static const uint32_t kMatrixSize{4};

    Matrix4x4();

    Matrix4x4(const Matrix4x4& other);

    ~Matrix4x4();

    Matrix4x4& operator=(const Matrix4x4& other);

    Matrix4x4& operator+=(const Matrix4x4& rhs);

    Matrix4x4& operator-=(const Matrix4x4& rhs);

    Matrix4x4& operator*=(const Matrix4x4& rhs);

    Matrix4x4& operator*=(T rhs);

    T* operator[](uint32_t i);

    const T* operator[](uint32_t i) const;

    T m[kMatrixSize * kMatrixSize];
};

template <typename T>
Matrix4x4<T> operator+(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs);

template <typename T>
Matrix4x4<T> operator-(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs);

template <typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs);

template <typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& lhs, T rhs);

Vector3<float> operator*(const Matrix4x4<float>& lhs, const Vector3<float>& rhs);

// -------------------------------------------------------------------------- //

template <typename T>
Matrix4x4<T>::Matrix4x4() : m{} {}

template <typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4& other) : m{} {
    std::copy(other.m, other.m + kMatrixSize * kMatrixSize, m);
}

template <typename T>
Matrix4x4<T>::~Matrix4x4() {}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4& other) {
    if (this == &other) {
        return *this;
    }

    std::copy(other.m, other.m + kMatrixSize * kMatrixSize, m);

    return *this;
}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator+=(const Matrix4x4& rhs) {
    for (uint32_t i = 0; i < kMatrixSize * kMatrixSize; ++i) {
        m[i] += rhs.m[i];
    }

    return *this;
}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator-=(const Matrix4x4& rhs) {
    for (uint32_t i = 0; i < kMatrixSize * kMatrixSize; ++i) {
        m[i] -= rhs.m[i];
    }

    return *this;
}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator*=(const Matrix4x4& rhs) {
    T buffer[kMatrixSize * kMatrixSize] = {};

    for (uint32_t i = 0; i < kMatrixSize; ++i) {
        for (uint32_t j = 0; j < kMatrixSize; ++j) {
            for (uint32_t k = 0; k < kMatrixSize; ++k) {
                buffer[i * kMatrixSize + j] += m[i * kMatrixSize + k] * rhs.m[k * kMatrixSize + j];
            }
        }
    }

    std::copy(buffer, buffer + kMatrixSize * kMatrixSize, m);

    return *this;
}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator*=(T rhs) {
    for (uint32_t i = 0; i < kMatrixSize * kMatrixSize; ++i) {
        m[i] * rhs;
    }

    return *this;
}

template <typename T>
T* Matrix4x4<T>::operator[](uint32_t i) {
    assert(i < kMatrixSize);
    
    return &m[i * kMatrixSize];
}

template <typename T>
const T* Matrix4x4<T>::operator[](uint32_t i) const {
    assert(i < kMatrixSize);
    
    return &m[i * kMatrixSize];
}

template <typename T>
Matrix4x4<T> operator+(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs) {
    Matrix4x4<T> result(lhs);
    lhs += rhs;
    return result;
}

template <typename T>
Matrix4x4<T> operator-(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs) {
    Matrix4x4<T> result(lhs);
    lhs -= rhs;
    return result;
}

template <typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& lhs, const Matrix4x4<T>& rhs) {
    Matrix4x4<T> result(lhs);
    lhs *= rhs;
    return result;
}

template <typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& lhs, T rhs) {
    Matrix4x4<T> result(lhs);
    lhs *= rhs;
    return result;
}

#endif // __MATRIX4X4_HPP__
