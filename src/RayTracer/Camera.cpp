#include "Camera.hpp"

Camera::Camera() : right_{0.f, 1.f, 0.f}, up_{0.f, 0.f, 1.f}, forward_{1.f, 0.f, 0.f},
                   position_{0.f, 0.f, -4.f}, view_matrix_{} {
    UpdateVeiwMatrix();
}

Camera::~Camera() {}

const Matrix4x4<float>& Camera::GetViewMatrix() const {
    return view_matrix_;
}

void Camera::UpdateVeiwMatrix() {
    view_matrix_[0][0] = right_.x;
    view_matrix_[1][0] = up_.x;
    view_matrix_[2][0] = forward_.x;
    view_matrix_[3][0] = 0.f;
    
    view_matrix_[0][1] = right_.y;
    view_matrix_[1][1] = up_.y;
    view_matrix_[2][1] = forward_.y;
    view_matrix_[3][1] = 0.f;
    
    view_matrix_[0][2] = right_.z;
    view_matrix_[1][2] = up_.z;
    view_matrix_[2][2] = forward_.z;
    view_matrix_[3][2] = 0.f;

    view_matrix_[0][3] = position_.x;
    view_matrix_[1][3] = position_.y;
    view_matrix_[2][3] = position_.z;
    view_matrix_[3][3] = 1.f;
}
