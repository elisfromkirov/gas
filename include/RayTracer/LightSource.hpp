#ifndef __LIGHT_SOURCE_HPP__
#define __LIGHT_SOURCE_HPP__

#include "Color.hpp"
#include "SpaceDepenedentData.hpp"
#include "Matrix4x4.hpp"
#include "Vector3.hpp"

class LightSource {
public:
    LightSource(const Vector3<float>& postion, const Color& color);
    ~LightSource();

    void TransformToCameraSpace(const Matrix4x4<float>& veiw_matrix);

    const Vector3<float>& GetPosition() const;

    const Vector3<float>& GetWorldPosition() const;
    void SetWorldPosition(const Vector3<float>& position);

    const Color& GetColor() const;
    void SetColor(const Color& color);

private:
    SpaceDependentData<Vector3<float>> position_;
    Color          color_;
};

#endif // __LIGHT_SOURCE_HPP__
