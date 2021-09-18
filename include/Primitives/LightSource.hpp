#ifndef __LIGHT_SOURCE_HPP__
#define __LIGHT_SOURCE_HPP__

#include "Vector3.hpp"
#include "Color.hpp"

class LightSource {
public:
    LightSource(const Vector3<float>& postion, const Color& color);

    ~LightSource();

    const Vector3<float>& GetPosition() const;
    void SetPostion(const Vector3<float>& position);

    const Color& GetColor() const;
    void SetColor(const Color& color);

private:
    Vector3<float> position_;
    Color          color_;
};

#endif // __LIGHT_SOURCE_HPP__
