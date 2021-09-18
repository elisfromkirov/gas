#ifndef __RAY_TRACER_HPP__
#define __RAY_TRACER_HPP__

#include "Color.hpp"
#include "LightSource.hpp"
#include "Vector3.hpp"
#include "List.hpp"
#include "IShape.hpp"
#include "Surface.hpp"

class RayTracer {
public:
    RayTracer(Window& window);

    ~RayTracer();

    void Present();

    void AddLightSource(LightSource* light_source);

    void Trace(List<IShape*>& shapes);

private:
    Color TraceRay(List<IShape*>& shapes, const Ray& ray);
    Color ComputeColor(IShape* shape, const Ray& ray, const Vector3<float>& point);

    Surface surface_;

    List<LightSource*> light_sources_;
};

#endif // __RAY_TRACER_HPP__
