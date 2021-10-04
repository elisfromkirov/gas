#include "Box.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "RayTracer.hpp"

#include "Molecule.hpp"
#include "MoleculeManager.hpp"

#include "Window.hpp"

const uint32_t kWindowWidth{800};
const uint32_t kWindowHeight{600};

const Material material{Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 200}; 

int main() {
    Window window{"ray tracer", 0, 0, kWindowWidth, kWindowHeight};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    Camera camera{};
    scene.RegisterCamera(&camera);

    Vector3<float> light_position{0.8, 0.3, -0.8};
    LightSource light{light_position, Color{1.0, 1.0, 1.0}};
    scene.RegisterLightSource(&light);

    PhysicsEngine physics_engine{};

    MoleculeManager manager{&ray_tracer, &scene, &physics_engine};
    
    manager.AddMolecule(new SphereMolecule(Vector3<float>{0.5, 0.0, 0.0}, 0.4, &material));
    manager.AddVessel(new Vessel());

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        manager.DrawMolecules();

        window.UpdateWindowSurface();
    }

    return 0;
}
