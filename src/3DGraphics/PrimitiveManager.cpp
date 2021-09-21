#include "PrimitiveManager.hpp"

PrimitiveManager::PrimitiveManager() {}

PrimitiveManager::~PrimitiveManager() {
    for (auto it = primitives_.begin(); it != primitives_.end(); ++it) {
        delete *it;
    }
    for (auto it = light_sources_.begin(); it != light_sources_.end(); ++it) {
        delete *it;
    }
}

void PrimitiveManager::AddPrimitive(IPrimitive* primitive) {
    primitives_.push_back(primitive);
}

void PrimitiveManager::AddLightSource(LightSource* light_source) {
    light_sources_.push_back(light_source);
}

void PrimitiveManager::DrawPrimitives(RayTracer& ray_tracer) const {
    ray_tracer.Trace(primitives_, light_sources_);
    ray_tracer.Present();
}
