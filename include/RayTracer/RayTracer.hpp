#ifndef __RAY_TRACER_HPP__
#define __RAY_TRACER_HPP__

#include <cstdint>
#include <cassert>

#include "Scene.hpp"
#include "WindowSurface.hpp"

class RayTracer {
public:
    RayTracer(WindowSurface window_surface);
    ~RayTracer();

    void Trace         (      Scene* scene);

private:
    void TransformScene(      Scene* scene);

    void TraceScene    (const Scene* scene);    

    Color TraceRay     (const Scene* scene, const Ray& ray);

    Color ComputeColor (const Scene* scene, const Ray& ray, const IPrimitive* primitive,
                        const Vector3<float>& intersection_point);

private:
    WindowSurface window_surface_;
};

#endif // __RAY_TRACER_HPP__
