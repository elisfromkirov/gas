#ifndef __RAY_TRACER_HPP__
#define __RAY_TRACER_HPP__

#include "Color.hpp"
#include "Vector3.hpp"
#include "List.hpp"
#include "IShape.hpp"
#include "Surface.hpp"

class RayTracer {
public:
    RayTracer(Window& window);

    ~RayTracer();

    void Trace(List<IShape*>& primitives);

    void Present();

private:
    Color TraceRay(List<IShape*>& shapes, const Ray& ray);

    Surface surface_;
    Vector3<float> light_;
};

#endif // __RAY_TRACER_HPP__
