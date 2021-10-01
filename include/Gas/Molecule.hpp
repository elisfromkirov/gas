#ifndef __MOLECULE_HPP__
#define __MOLECULE_HPP__

#include "GraphicsComponent.hpp"

class IMolecule {
public:
    virtual ~IMolecule() {}

    virtual IGraphicsComponent* GetGraphicsComponent() = 0;
};

class SphereMolecule : public IMolecule {
public:
    SphereMolecule(const Vector3<float>& center, float radius, const Material* material);
    virtual ~SphereMolecule() override = default;

    virtual IGraphicsComponent* GetGraphicsComponent() override;

private:
    SphereGraphicsComponent graphics_component_;
};

#endif // __MOLECULE_HPP__
