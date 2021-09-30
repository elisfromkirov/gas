#ifndef __MOLECULE_HPP__
#define __MOLECULE_HPP__

#include "IPrimitive.hpp"
#include "Sphere.hpp"

class IMolecule {
public:
    virtual ~IMolecule() {}

    virtual IPrimitive* GetGraphicsComponent() = 0;
};

class SphereMolecule : public IMolecule {
public:
    SphereMolecule(const Vector3<float>& center, float radius, const Material* material);
    virtual ~SphereMolecule();

    virtual IPrimitive* GetGraphicsComponent() override;

private:
    Sphere sphere_;
};

#endif // __MOLECULE_HPP__
