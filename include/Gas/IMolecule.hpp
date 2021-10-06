#ifndef __I_MOLECULE_HPP__
#define __I_MOLECULE_HPP__

#include "IGraphicsEntity.hpp"
#include "IPhysicsEntity.hpp"

class IMolecule : public IPhysicsEntity, public IGraphicsEntity {
public:
    virtual bool IsValid() const = 0;

    virtual bool DidMoleculeCollide() const = 0;





    // virtual IPhysicsEntity* 

    // virtual void MakeValid() = 0;

    // virtual bool NeedDoChemistry() const = 0;

    

    // virtual void DoChemistry() const = 0;
};

#endif // __I_MOLECULE_HPP__
