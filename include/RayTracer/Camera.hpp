#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "Vector3.hpp"
#include "Matrix4x4.hpp"

class Camera {
public:
    Camera();
    ~Camera();

    const Matrix4x4<float>& GetViewMatrix() const;

private:
    void UpdateVeiwMatrix();

private:
    Vector3<float> right_;
    Vector3<float> up_;
    Vector3<float> forward_;
    Vector3<float> position_;

    Matrix4x4<float> view_matrix_;
};

#endif // __CAMERA_HPP__
