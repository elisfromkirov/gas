#ifndef __I_GRAPHICS_ENTITY_HPP__
#define __I_GRAPHICS_ENTITY_HPP__

class Scene;

class IGraphicsEntity {
public:
    virtual ~IGraphicsEntity() {}

    virtual void RegisterOnScene(Scene* scene) = 0;
    virtual void UnregisterOnScene(Scene* scene) = 0;
};

#endif // __I_GRAPHICS_ENTITY_HPP__
