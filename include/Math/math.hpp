#pragma once

#include <cassert>
#include <cmath>

namespace Math {

static const float epsilon = 0.000001f;
static const float pi  = 3.141592f;

template <size_t dim>
class Vector;

template <size_t dim>
class Matrix;

template <size_t dim>
class Vector {
public:
    Vector() : length_(0.f) {
        SetBuffer(buffer_, 0.f);
    } 

    Vector(const Vector& other) : length_(other.length_) {
        CopyBuffer(buffer_, other.buffer_);
    }

    ~Vector() {}

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        CopyBuffer(buffer_, other.buffer_);
        length_ = other.length_;

        return *this;
    }

    Vector& operator+=(const Vector& term) {
        for (size_t i = 0; i < dim; ++i) {
            buffer_[i] += term.buffer_[i];
        }

        length_ = CalculateLength(buffer_);

        return *this;
    }

    Vector& operator-=(const Vector& subtrahend) {
        for (size_t i = 0; i < dim; ++i) {
            buffer_[i] -= subtrahend.buffer_[i];
        }

        length_ = CalculateLength(buffer_);        

        return *this;
    }
    
    Vector& operator*=(float factor) {
        for (size_t i = 0; i < dim; ++i) {
            buffer_[i] *= factor;
        }

        length_ *= factor;

        return *this;
    }
    
    Vector& operator/=(float divisor) {
        assert(epsilon < fabs(divisor));

        for (size_t i = 0; i < dim; ++i) {
            buffer_[i] /= divisor;
        }

        length_ /= divisor;
    
        return *this;
    }

    Vector& operator+() {
        return *this;
    }
    
    const Vector operator-() {
        Vector result(*this);
        return result *= (-1.f);
    }

    friend const Vector operator+(const Vector& lhs, const Vector& rhs) {
        Vector result(lhs);
        return result += rhs;
    }

    friend const Vector operator-(const Vector& lhs, const Vector& rhs) {
        Vector result(lhs);
        return result -= rhs;
    }

    friend const Vector operator*(const Vector& lhs, float rhs) {
        Vector result(lhs);
        return result *= rhs;
    }

    friend const Vector operator/(const Vector& lhs, float rhs) {
        Vector result(lhs);
        return result /= rhs;
    }

    friend float operator*(const Vector& lhs, const Vector& rhs) {
        float dot_product = 0.f;

        for (size_t i = 0; i < dim; ++i) {
            dot_product += lhs.buffer_[i] * rhs.buffer_[i];
        }

        return dot_product;
    }

    float& operator[](size_t index) {
        assert(index < dim);

        return buffer_[index];
    }

    const float& operator[](size_t index) const {
        assert(index < dim);

        return buffer_[index];
    }

    float GetLength() const {
        return length_;
    }
    
    void Normalize() {
        assert(epsilon < length_);

        *this /= length_;
    }

private:
    float buffer_[dim];
    float length_;

    static void CopyBuffer(float* destination, const float* source) {
        for (size_t i = 0; i < dim; ++i) {
            destination[i] = source[i];
        }
    }

    static void SetBuffer(float* buffer, float value) {
        for (size_t i = 0; i < dim; ++i) {
            buffer[i] = value;
        }
    }

    static float CalculateLength(const float* buffer) {
        float square = 0.f;

        for(size_t i = 0; i < dim; ++i) {
            square += buffer[i] * buffer[i];
        }

        return sqrtf(square);
    }
};

const Vector<3> CrossProduct(const Vector<3>& lhs, const Vector<3>& rhs) {
    Vector<3> result;

    result[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
    result[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
    result[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];

    return result;
}

template <size_t dim>
class Matrix {
public:
    Matrix() {
        SetBuffer(buffer_, 0.f);
    }

    Matrix(const Matrix& other) {
        CopyBuffer(buffer_, other.buffer_);
    }
    
    ~Matrix() {}

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        CopyBuffer(buffer_, other.buffer_);

        return *this;
    }

    Matrix& operator+=(const Matrix& term) {
        for (size_t i = 0; i < dim * dim; ++i) {
            buffer_[i] += term.buffer_[i];
        }

        return *this;
    }

    Matrix& operator-=(const Matrix& subtrahend) {
        for (size_t i = 0; i < dim * dim; ++i) {
            buffer_[i] -= subtrahend.buffer_[i];
        }

        return *this;
    }

    Matrix& operator*=(float factor) {
        for (size_t i = 0; i < dim * dim; ++i) {
            buffer_[i] *= factor;
        }

        return *this;
    }

    Matrix& operator/=(float divisor) {
        assert(epsilon < fabs(divisor));

        for (size_t i = 0; i < dim * dim; ++i) {
            buffer_[i] /= divisor;
        }

        return *this;
    }

    Matrix& operator+() {
        return *this;
    }

    Matrix& operator-() {
        Matrix result(*this);
        return result *= -1.f;
    }

    friend const Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        Matrix result(lhs);
        return result += rhs;
    }

    friend const Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
        Matrix result(lhs);
        return result -= rhs;
    }

    friend const Matrix operator*(const Matrix& lhs, float rhs) {
        Matrix result(lhs);
        return result *= rhs;
    }

    friend const Matrix operator/(const Matrix& lhs, float rhs) {
        Matrix result(lhs);
        return result /= rhs;
    }

    friend const Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        Matrix result;

        for (size_t i = 0; i < dim; ++i) {
            for (size_t j = 0; j < dim; ++j) {
                result.buffer_[i * dim + j] = 0;
                for (size_t k = 0; k < dim; ++k) {
                    result.buffer_[i * dim + j] += lhs.buffer_[i * dim + k] * rhs.buffer_[k * dim + j];
                }
            }
        }

        return result;
    }

    friend const Vector<dim> operator*(const Matrix& lhs, const Vector<dim>& rhs) {
        Vector<dim> result;

        for (size_t i = 0; i < dim; ++i) {
            result[i] = 0;
            for (size_t j = 0; j < dim; ++j) {
                result[i] += lhs.buffer_[i * dim + j] * rhs[j];
            }
        }        

        return result;
    }

    float* operator[](size_t index) {
        assert(index < dim);

        return &buffer_[index * dim];
    }

    const float* operator[](size_t index) const {
        assert(index < dim);

        return &buffer_[index * dim];
    }

private:
    float buffer_[dim * dim];

    static void CopyBuffer(float* destination, const float* source) {
        for (size_t i = 0; i < dim * dim; ++i) {
            destination[i] = source[i];
        }
    }

    static void SetBuffer(float* buffer, float value) {
        for (size_t i = 0; i < dim * dim; ++i) {
            buffer[i] = value;
        }    
    }
};

}; // Math
