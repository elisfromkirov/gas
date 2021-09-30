#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>

#include "IPrimitive.hpp"
#include "LightSource.hpp"

class RayTracer;

class Scene {
public:
    void AddPrimitive(IPrimitive* primitive);

    void AddLightSource(LightSource* light_source);

private:
    std::list<IPrimitive*>  primitives_;
    std::list<LightSource*> light_sources_;

    friend class RayTracer;
};

#endif // __SCENE_HPP__
