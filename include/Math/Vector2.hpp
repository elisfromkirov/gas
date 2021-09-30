#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

template <typename T>
struct Vector2 {
    Vector2();

    Vector2(T x, T y);

    Vector2(const Vector2& other);

    ~Vector2();

    Vector2& operator=(const Vector2& other);

    Vector2& operator+=(const Vector2& rhs);

    Vector2& operator-=(const Vector2& rhs);

    Vector2& operator*=(T rhs);

    T x;
    T y;
};

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T rhs);

template <typename T>
T DotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs);

float GetLength(const Vector2<float>& vector);

Vector2<float> Normalize(const Vector2<float>& vector);

// -------------------------------------------------------------------------- //

template <typename T>
Vector2<T>::Vector2() : x{}, y{} {}

template <typename T>
Vector2<T>::Vector2(T x, T y) : x{x}, y{y} {}

template <typename T>
Vector2<T>::Vector2(const Vector2& other) : x{other.x}, y{other.y} {}

template <typename T>
Vector2<T>::~Vector2() {}

template <typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2& other) {
    if (this == &other) {
        return *this;
    }

    x = other.x;
    y = other.y;

    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2& rhs) {
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(T rhs) {
    x *= rhs;
    y *= rhs;

    return *this;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
    Vector2<T> result(lhs);
    result += rhs;
    return result;
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
    Vector2<T> result(lhs);
    result -= rhs;
    return result;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T rhs) {
    Vector2<T> result(lhs);
    result *= rhs;
    return result;
}

template <typename T>
T DotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float GetLength(const Vector2<float>& vector);

Vector2<float> Normalize(const Vector2<float>& vector);

#endif // __VECTOR2_HPP__
