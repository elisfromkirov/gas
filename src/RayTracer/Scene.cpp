#include "Scene.hpp"

void Scene::RegisterCamera(Camera* camera) {
    camera_ = camera;
}

void Scene::RegisterPrimitive(IPrimitive* primitive) {
    primitives_.push_back(primitive);
}

void Scene::RegisterLightSource(LightSource* light_source) {
    light_sources_.push_back(light_source);
}
