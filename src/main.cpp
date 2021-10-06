#include <ctime>
#include <cstring>

#include "Box.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Surface.hpp"
#include "RayTracer.hpp"

#include "BoxMolecule.hpp"
#include "SphereMolecule.hpp"
#include "Vessel.hpp"
#include "MoleculeManager.hpp"

#include "Window.hpp"

void SetFPS(Window& window, clock_t begin, clock_t end);
void FillVessel(MoleculeManager& molecule_manager);

int main() {
    Window window{"ray tracer"};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    Camera camera{};
    scene.RegisterCamera(&camera);

    LightSource light_source(Vector3<float>{1.9,  0.4f, -0.4f}, Color{1.0, 1.0, 1.0});
    scene.RegisterLightSource(&light_source);

    PhysicsEngine physics_engine{};

    MoleculeManager molecule_manager{&ray_tracer, &scene, &physics_engine};
    FillVessel(molecule_manager);

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        molecule_manager.DrawMolecules();

        molecule_manager.SimulateMoleculesPhysics(0.1);

        molecule_manager.SimulateMoleculesChemistry();

        window.UpdateWindowSurface();
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

const uint32_t kSphereMoleculesCount{4};
const uint32_t kBoxMoleculesCount{2};

void FillVessel(MoleculeManager& molecule_manager) {
    for (uint32_t i = 0; i < kSphereMoleculesCount; ++i) {
        Vector3<float> center{};
        center.x = static_cast<float>(rand() % 8) * 0.2f - 0.8f;
        center.y = static_cast<float>(rand() % 8) * 0.2f - 0.8f;
        center.z = static_cast<float>(rand() % 8) * 0.2f - 0.8f;

        Vector3<float> velocity{};
        velocity.x = static_cast<float>(rand() % 16) * 0.025f - 0.2f;
        velocity.y = static_cast<float>(rand() % 16) * 0.025f - 0.2f;
        velocity.z = static_cast<float>(rand() % 16) * 0.025f - 0.2f;

        molecule_manager.AddMolecule(new SphereMolecule(center, 0.1, velocity));
    }

    for (uint32_t i = 0; i < kBoxMoleculesCount; ++i) {
        Vector3<float> center{};
        center.x = static_cast<float>(rand() % 8) * 0.2f - 0.8f;
        center.y = static_cast<float>(rand() % 8) * 0.2f - 0.8f;
        center.z = static_cast<float>(rand() % 8) * 0.2f - 0.8f;

        Vector3<float> velocity{};
        velocity.x = static_cast<float>(rand() % 16) * 0.025f - 0.2f;
        velocity.y = static_cast<float>(rand() % 16) * 0.025f - 0.2f;
        velocity.z = static_cast<float>(rand() % 16) * 0.025f - 0.2f;

        Vector3<float> size{0.2, 0.2, 0.2};

        molecule_manager.AddMolecule(new BoxMolecule(center, size, velocity));
    }

    molecule_manager.AddVessel(new Vessel());
}
