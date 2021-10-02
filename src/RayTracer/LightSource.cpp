#include "LightSource.hpp"

LightSource::LightSource(const Vector3<float>& postion, const Color& color)
    : position_{postion, postion}, color_{color} {}

LightSource::~LightSource() {}

void LightSource::TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix) {
    position_.camera_space = veiw_matrix * position_.world_space;
}

const Vector3<float>& LightSource::GetPosition() const {
    return position_.camera_space;
}

const Vector3<float>& LightSource::GetWorldPosition() const {
    return position_.world_space;
}

void LightSource::SetWorldPosition(const Vector3<float>& position) {
    position_.world_space = position;
}

const Color& LightSource::GetColor() const {
    return color_;
}

void LightSource::SetColor(const Color& color) {
    color_ = color;
}
