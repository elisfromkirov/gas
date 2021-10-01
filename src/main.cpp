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
    scene.RegisterLightSource(&dynamic_light);

    Material material{Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 500};

    MoleculeManager molecule_manager{&ray_tracer, &scene};
    molecule_manager.AddMolecule(new SphereMolecule(Vector3<float>{ 0.0, -0.3,  3.0}, 0.7, &material));

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
