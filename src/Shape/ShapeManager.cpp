#include "ShapeManager.hpp"

ShapeManager::ShapeManager() : shapes_{kMaxShapeCount} {}

ShapeManager::~ShapeManager() {
    for (auto iter = shapes_.Begin(); iter != shapes_.End(); ++iter) {
        IShape* shape = *iter;
        delete shape;
    }
}

void ShapeManager::RegisterShape(IShape* shape) {
    shapes_.InsertBack(shape);
}

void ShapeManager::DrawShapes(RayTracer& ray_traycer) {
    ray_traycer.Trace(shapes_);
}
