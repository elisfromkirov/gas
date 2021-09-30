#include "Scene.hpp"

void Scene::AddPrimitive(IPrimitive* primitive) {
    primitives_.push_back(primitive);
}

void Scene::AddLightSource(LightSource* light_source) {
    light_sources_.push_back(light_source);
}
