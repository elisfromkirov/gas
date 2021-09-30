#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Triangle.hpp"
#include "RayTracer.hpp"

#include "Molecule.hpp"
#include "MoleculeManager.hpp"

#include "Window.hpp"

int main() {
    Window window{"ray tracer", 0, 0, 800, 600};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    LightSource dynamic_light{Vector3<float>{2.0, -3.0, 0.0}, Color{1.0, 1.0, 1.0}};
    scene.AddLightSource(&dynamic_light);

    Material material{Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 500};

    scene.AddPrimitive(new Triangle(Vector3<float>{0.0, 0.0, 3.0}, 
                                    Vector3<float>{0.0, 1.0, 3.0},
                                    Vector3<float>{1.0, 0.0, 3.0}, 
                                    &material));
    scene.AddPrimitive(new Triangle(Vector3<float>{1.0, 0.0, 3.0}, 
                                    Vector3<float>{0.0, 1.0, 3.0},
                                    Vector3<float>{1.0, 1.0, 3.0},
                                    &material));

    bool running = true;
    Vector3<float> position{2.0, -2.0, 0.0};
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        ray_tracer.TraceScene(&scene);

        window.UpdateWindowSurface();
    }

    return 0;
}
