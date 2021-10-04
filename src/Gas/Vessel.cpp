#include "Vessel.hpp"

Vessel::Vessel() : graphics_component_{} {}

Vessel::~Vessel() {}

IGraphicsComponent* Vessel::GetGraphicsComponent() {
    return &graphics_component_;
}
