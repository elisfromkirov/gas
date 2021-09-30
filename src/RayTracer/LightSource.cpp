#include "LightSource.hpp"

LightSource::LightSource(const Vector3<float>& postion, const Color& color)
    : position_{postion}, color_{color} {}

LightSource::~LightSource() {}

const Vector3<float>& LightSource::GetPosition() const {
    return position_;
}
void LightSource::SetPosition(const Vector3<float>& position) {
    position_ = position;
}

const Color& LightSource::GetColor() const {
    return color_;
}
void LightSource::SetColor(const Color& color) {
    color_ = color;
}
