#include <cassert>
#include <cstdint>
#include <cfloat>
#include <math.h>

#include "Color.hpp"
#include "RayTracer.hpp"

RayTracer::RayTracer(Window& window)
    : surface_{window}, light_{2.0f, -1.0f, 0.0f} {}

RayTracer::~RayTracer() {}

void RayTracer::Trace(List<IShape*>& shapes) {
    Ray ray{Vector3<float>{0.0, 0.0, 0.0}, Vector3<float>{0.0, 0.0, 0.0}};

    int32_t width  = surface_.GetWidth();
    int32_t height = surface_.GetHeight();

    for (int32_t y = 0; y < height; ++y) {
       for (int32_t x = 0; x < width; ++x) {
            ray.direction.x = (float)(2 * x - width ) / (float)(2 * width);
            ray.direction.y = (float)(2 * y - height) / (float)(2 * width);
            ray.direction.z = -1.0;

            surface_[y][x] = ColorToRGB888(TraceRay(shapes, ray));
        }
    }
}

void RayTracer::Present() {
    surface_.Update();
}

Color RayTracer::TraceRay(List<IShape*>& shapes, const Ray& ray) {
    IShape* nearest_shape = nullptr;

    float min_t = FLT_MAX;
    for (auto iter = shapes.Begin(); iter != shapes.End(); ++iter) {
        IShape* shape = *iter;
        float   t     = 0.0;
        
        if (shape->RayIntersect(ray, &t)) {
            if (t < min_t) {
                min_t = t;
                nearest_shape = shape;
            }
        }
    }
    
    if (nearest_shape == nullptr) {
        return Color{0.0, 0.0, 0.0};
    }

    // point of intersection of ray and primitive
    Vector3<float> point {ray.origin + ray.direction * min_t}; 
    
    // normal of primitive at the point of intersection
    Vector3<float> normal{nearest_shape->GetNormal(point)}; 

    return nearest_shape->GetColor();
}

/*
float RayTracer::ComputeLights(const Vector& point, const Vector& normal, const Vector& direction, const Material& material) {    
    float intensity = 0.0f;

    Vector light_direction = Normalize(point - light_);

    float diffuse_reflection_intensity = material.diffuse * DotProduct(light_direction, normal);
    if (diffuse_reflection_intensity > 0.0f) {
        intensity += diffuse_reflection_intensity;
    }

    Vector reflected_light_direction = Normalize(normal * 2.0f * DotProduct(normal, light_direction) - light_direction);

    float specular_diffuse_reflection = Power(DotProduct(reflected_light_direction, direction) / direction.GetLength(), material.specular);
    if (specular_diffuse_reflection > 0.0f) {
        intensity += specular_diffuse_reflection;
    }

    return intensity;
}
*/
