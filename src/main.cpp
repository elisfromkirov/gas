#include <ctime>
#include <cstring>

#include "Box.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "RayTracer.hpp"

#include "Molecule.hpp"
#include "MoleculeManager.hpp"

#include "Window.hpp"

void SetFPS(Window& window, clock_t begin, clock_t end);

int main() {
    Window window{"ray tracer", 0, 0, 800, 600};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    Camera camera{};
    scene.RegisterCamera(&camera);

    LightSource light_sources[] = {
        LightSource(Vector3<float>{1.9,  0.9f, -0.9f}, Color{1.0, 1.0, 1.0}),
        LightSource(Vector3<float>{1.9, -0.9f, -0.9f}, Color{1.0, 1.0, 1.0})
    };
    scene.RegisterLightSource(&light_sources[0]);
    scene.RegisterLightSource(&light_sources[1]);

    PhysicsEngine physics_engine{};

    Material material{Color{0.1, 0.0, 0.0}, Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 100}; 

    MoleculeManager manager{&ray_tracer, &scene, &physics_engine};

    manager.AddMolecule(new SphereMolecule(Vector3<float>{0.5, 0.0, 0.0}, 0.1, Vector3<float>{0.4, -0.3, 0.4}, &material));
    manager.AddMolecule(new SphereMolecule(Vector3<float>{0.0, 0.5, 0.0}, 0.1, Vector3<float>{0.4, 0.0, 0.3}, &material));
    manager.AddMolecule(new SphereMolecule(Vector3<float>{-0.05, -0.7, -0.05}, 0.1, Vector3<float>{0.0,  0.3, 0.0}, &material));
    manager.AddMolecule(new SphereMolecule(Vector3<float>{ 0.05,  0.7,  0.05}, 0.1, Vector3<float>{0.0, -0.3, 0.0}, &material));

    manager.AddVessel(new Vessel());

    bool running = true;
    while (running) {
        clock_t time = clock();

        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        manager.DrawMolecules();

        manager.MoveMolecules(0.1);

        window.UpdateWindowSurface();

        SetFPS(window, time, clock());
    }

    return 0;
}

void SetFPS(Window& window, clock_t begin, clock_t end) {
    static const uint32_t size = 128;
    static char buffer[size]   = {};
    memset(buffer, 0, size);

    sprintf(buffer, "%lg", float(CLOCKS_PER_SEC)/float(end - begin));
    
    window.SetTitle(buffer);
}
