#include <unistd.h>

#include "Primitive.hpp"
#include "PrimitiveManager.hpp"
#include "RayTracer.hpp"

#include "PhysicsEventListener.hpp"

#include "EventManager.hpp"

#include "MoleculeEntity.hpp"
#include "VesselEntity.hpp"

#include "PhysicsComponent.hpp"
#include "PhysicsComponentManager.hpp"
#include "PhysicsEngine.hpp"

#include "Window.hpp"

int main() {
    EventManager event_manager{};

    PhysicsEngine physics_engine{&event_manager};
    PhysicsEventListener physics_event_listener{};
    event_manager.RegisterListener(&physics_event_listener);

    PrimitiveManager primitive_manager{};
    PhysicsManager   physics_manager{};

    Window window{"gas"};
    RayTracer ray_tracer{window};

    LightSource* light_source = new LightSource(
        Vector3<float>{2.0,  2.0, 0.0}, Color{1.0, 1.0, 1.0});
    primitive_manager.AddLightSource(light_source);

    Sphere* sphere = new Sphere(
        Vector3<float>{ 0.0, -0.3,  3.0}, 0.7, Color{1.0, 0.0, 0.0}, Material{0.6, 100, 0.2});
    
    SpherePhysicsComponent* sphere_physics_component = new SpherePhysicsComponent(
        SphereGeom{Vector3<float>{0.0, -0.3,  3.0}, 0.7}, Vector3<float>{0.0, 0.0, 1.0}, 0.0);

    MoleculeEntity molecule{sphere, sphere_physics_component};
    primitive_manager.AddPrimitive(sphere);
    physics_manager.AddPhysicsComponent(sphere_physics_component, &molecule);

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        physics_manager.SimulatePhysics(physics_engine);

        event_manager.DispatchAllEvents();

        primitive_manager.DrawPrimitives(ray_tracer);

        usleep(1000);
    }

    return 0;
}
