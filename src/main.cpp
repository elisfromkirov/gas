#include "Sphere.hpp"
#include "ShapeManager.hpp"
#include "RayTracer.hpp"
#include "Window.hpp"

int main() {
    Window window{"chemistry"};
    RayTracer ray_tracer{window};

    ray_tracer.AddLightSource(new LightSource(Vector3<float>{2.0,  2.0, 0.0}, Color{1.0, 1.0, 1.0}));

    ShapeManager manager{};
    manager.RegisterShape(new Sphere(Vector3<float>{ 0.0, -0.3,  3.0}, 0.7, Color{1.0, 0.0, 0.0}, Material{0.6, 1000, 0.2}));
    manager.RegisterShape(new Sphere(Vector3<float>{ 2.0,  0.0,  4.0}, 0.7, Color{0.0, 1.0, 0.0}, Material{0.5,  500, 0.2}));
    manager.RegisterShape(new Sphere(Vector3<float>{-2.0,  0.0,  4.0}, 0.7, Color{0.0, 0.0, 1.0}, Material{0.5,  800, 0.2}));

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }        
        
        manager.DrawShapes(ray_tracer);

        ray_tracer.Present();
    }

    return 0;
}