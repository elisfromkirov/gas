#ifndef __RAY_TRACER_HPP__
#define __RAY_TRACER_HPP__

#include <list>

#include "Color.hpp"
#include "Primitive.hpp"
#include "LightSource.hpp"
#include "Surface.hpp"

class RayTracer {
public:
    RayTracer(Window& window);
    ~RayTracer();

    void Trace(const std::list<IPrimitive*>& primitives, 
               const std::list<LightSource*>& light_sources);

    void Present();

private:
    Color TraceRay(const std::list<IPrimitive*>& primitives, 
                   const std::list<LightSource*>& light_sources, const Ray& ray);

    Color ComputeColor(const IPrimitive* primitive, 
                       const std::list<LightSource*>& light_sources,
                       const Ray& ray, const Vector3<float>& point);

    Surface surface_;
};

#endif // __RAY_TRACER_HPP__
