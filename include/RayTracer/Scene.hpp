#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>

#include "Camera.hpp"
#include "IPrimitive.hpp"
#include "LightSource.hpp"

class RayTracer;

class Scene {
public:
    void RegisterCamera(Camera* camera);

    void RegisterPrimitive(IPrimitive* primitive);

    void RegisterLightSource(LightSource* light_source);

private:
    Camera* camera_;
    std::list<IPrimitive*>  primitives_;
    std::list<LightSource*> light_sources_;

    friend class RayTracer;
};

#endif // __SCENE_HPP__
