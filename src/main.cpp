#include "Box.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "RayTracer.hpp"

#include "Molecule.hpp"
#include "MoleculeManager.hpp"

#include "Window.hpp"

int main() {
    Window window{"ray tracer", 0, 0, 800, 600};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    Camera camera{};
    scene.RegisterCamera(&camera);

    LightSource light{Vector3<float>{2.0, 1.0, -1.0}, Color{1.0, 1.0, 1.0}};
    scene.RegisterLightSource(&light);

    Material material{Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 200};

    // Sphere sphere(Vector3<float>{0.0, 0.0, 0.0}, 0.7, &material);
    // scene.RegisterPrimitive(&sphere);

    Box box{Vector3<float>{0.0, -0.5, 0.4}, Vector3<float>{0.5, 0.5, 0.5}, &material};
    scene.RegisterPrimitive(&box);

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        ray_tracer.Trace(&scene);    

        window.UpdateWindowSurface();
    }

    return 0;
}
