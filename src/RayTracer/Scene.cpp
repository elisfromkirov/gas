#include "Scene.hpp"

void Scene::RegisterCamera(Camera* camera) {
    assert(camera != nullptr);
    
    camera_ = camera;
}

void Scene::RegisterPrimitive(IPrimitive* primitive) {
    assert(primitive != nullptr);

    primitives_.push_back(primitive);
}

void Scene::RegisterLightSource(LightSource* light_source) {
    assert(light_source != nullptr);

    light_sources_.push_back(light_source);
}
