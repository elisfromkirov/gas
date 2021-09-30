#include <float.h>
#include <math.h>

#include "RayTracer.hpp"

RayTracer::RayTracer(WindowSurface window_surface)
    : window_surface_{window_surface} {}

RayTracer::~RayTracer() {}

void RayTracer::TraceScene(const Scene* scene) {
    Ray ray{Vector3<float>{0.0, 0.0, 0.0}, Vector3<float>{0.0, 0.0, 0.0}};

    int32_t width  = static_cast<int32_t>(window_surface_.GetWidth());
    int32_t height = static_cast<int32_t>(window_surface_.GetHeight());

    for (int32_t y = 0; y < height; ++y) {
       for (int32_t x = 0; x < width; ++x) {
            ray.direction.x = static_cast<float>(2 * x - width ) / static_cast<float>(2 * width);
            ray.direction.y = static_cast<float>(2 * y - height) / static_cast<float>(2 * width);
            ray.direction.z = -1.0;

            window_surface_[y][x] = ColorToRGB888(TraceRay(scene, ray));
        }
    }
}

Color RayTracer::TraceRay(const Scene* scene, const Ray& ray) {
    const IPrimitive* nearest_primitive = nullptr;

    float min_t = FLT_MAX;
    for (auto primitive : scene->primitives_) {
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
    
    Vector3<float> intersection_point{ray.origin + ray.direction * min_t};
    return ComputeColor(scene, ray, nearest_primitive, intersection_point);
}

Color RayTracer::ComputeColor(const Scene* scene, const Ray& ray, const IPrimitive* primitive,
                              const Vector3<float>& point) {
    assert(primitive != nullptr);

    const Material* material{primitive->GetMaterial()};

    Vector3<float> direction{Normalize(ray.direction)   };
    Vector3<float> normal   {primitive->GetNormal(point)};

    Color result{0.0, 0.0, 0.0};

    for (auto light_source : scene->light_sources_) {
        Vector3<float> direction_to_light{Normalize(point - light_source->GetPosition())};
        
        float diffuse_reflection = DotProduct(direction_to_light, normal);
        if (diffuse_reflection > 0.0) {
            result += material->diffuse_color * light_source->GetColor() * diffuse_reflection;
        }

        Vector3<float> reflected_light{
            normal * 2.0f * DotProduct(normal, direction_to_light) - direction_to_light};

        float specular_reflection = pow(DotProduct(reflected_light, direction), material->specular);
        if (specular_reflection > 0.0 && diffuse_reflection > 0.0) {
            result += material->specular_color * light_source->GetColor() * specular_reflection;
        }
    }

    return result;
}
