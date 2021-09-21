#ifndef __PRIMITIVE_MANAGER_HPP__
#define __PRIMITIVE_MANAGER_HPP__

#include <list>

#include "LightSource.hpp"
#include "Primitive.hpp"
#include "RayTracer.hpp"

class PrimitiveManager {
public:
    PrimitiveManager();
    ~PrimitiveManager();

    void AddPrimitive(IPrimitive* primitive);

    void AddLightSource(LightSource* light_source);

    void DrawPrimitives(RayTracer& ray_tracer) const;

private:
    std::list<IPrimitive*>  primitives_;
    std::list<LightSource*> light_sources_;
};

#endif // __PRIMITIVE_MANAGER_HPP__
