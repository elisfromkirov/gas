#include <cassert>
#include <cstdint>
#include <cfloat>
#include <math.h>

#include "RayTracer.hpp"

RayTracer::RayTracer(Window& window) : surface_{window} {}

RayTracer::~RayTracer() {}

void RayTracer::Trace(const std::list<IPrimitive*>&  primitives, 
                      const std::list<LightSource*>& light_sources) {
    Ray ray{Vector3<float>{0.0, 0.0, 0.0}, Vector3<float>{0.0, 0.0, 0.0}};

    int32_t width  = surface_.GetWidth();
    int32_t height = surface_.GetHeight();

    for (int32_t y = 0; y < height; ++y) {
       for (int32_t x = 0; x < width; ++x) {
            ray.direction.x = (float)(2 * x - width ) / (float)(2 * width);
            ray.direction.y = (float)(2 * y - height) / (float)(2 * width);
            ray.direction.z = -1.0;

            surface_[y][x] = ColorToRGB888(TraceRay(primitives, light_sources, ray));
        }
    }
}

void RayTracer::Present() {
    surface_.Update();
}

Color RayTracer::TraceRay(const std::list<IPrimitive*>& primitives, 
                          const std::list<LightSource*>& light_sources, const Ray& ray) {
    const IPrimitive* nearest_primitive = nullptr;

    float min_t = FLT_MAX;
    for (auto iter = primitives.begin(); iter != primitives.end(); ++iter) {
        IPrimitive* primitive = *iter;
        assert(primitive);
        
        float t = 0.0;

        if (primitive->RayIntersect(ray, &t)) {
            if (t < min_t) {
                min_t = t;
                nearest_primitive = primitive;
            }
        }
    }

    if (nearest_primitive == nullptr) {
        return Color{0.0, 0.0, 0.0};
    }
    
    return ComputeColor(nearest_primitive, light_sources,
                        ray, Vector3<float>{ray.origin + ray.direction * min_t});
}

Color RayTracer::ComputeColor(const IPrimitive* primitive,
                              const std::list<LightSource*>& light_sources,
                              const Ray& ray, const Vector3<float>& point) {
    assert(primitive);

    Vector3<float> direction{Normalize(ray.direction)};

    Vector3<float> normal   {primitive->GetNormal(point)};
    Color          color    {primitive->GetColor()      };
    Material       material {primitive->GetMaterial()   };

    Color result{0.0, 0.0, 0.0};

    for (auto iter = light_sources.begin(); iter != light_sources.end(); ++iter) {
        LightSource* light_source = *iter;

        Vector3<float> point_light_direction{
            Normalize(point - light_source->GetPosition())};

        float diffuse_reflection_intensity = 
            material.diffuse * DotProduct(point_light_direction, normal);
        if (diffuse_reflection_intensity > 0.0) {
            result += color * light_source->GetColor() * diffuse_reflection_intensity;
        }

        Vector3<float> reflected_light_direction{
            normal * 2.0f * DotProduct(normal, point_light_direction) - point_light_direction};

        float specular_diffuse_reflection = 
            pow(DotProduct(reflected_light_direction, direction), material.specular);
        if (specular_diffuse_reflection > 0.0f) {
            result += color * specular_diffuse_reflection;
        }
    }

    return result;
}
