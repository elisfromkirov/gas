#ifndef __SPHERE_MANAGER_HPP__
#define __SPHERE_MANAGER_HPP__

#include "List.hpp"
#include "IShape.hpp"
#include "RayTracer.hpp"

class ShapeManager {
private:
    static const uint32_t kMaxShapeCount{128};

public:
    ShapeManager();

    ~ShapeManager();

    void RegisterShape(IShape* shape);

    void DrawShapes(RayTracer& ray_tracer);

private:
    List<IShape*> shapes_;
};

#endif // __SPHERE_MANAGER_HPP__
