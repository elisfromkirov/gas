#ifndef __I_GRAPHICS_ENTITY_HPP__
#define __I_GRAPHICS_ENTITY_HPP__

class IGraphicsComponent;

class IGraphicsEntity {
public:
    virtual ~IGraphicsEntity() {}

    virtual IGraphicsComponent* GetGraphicsComponent() = 0;
};

#endif // __I_GRAPHICS_ENTITY_HPP__
