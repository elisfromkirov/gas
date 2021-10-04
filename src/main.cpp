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

const float kSin = 0.087155f;
const float kCos = 0.996194f;

int main() {
    Window window{"ray tracer", 0, 0, kWindowWidth, kWindowHeight};

    RayTracer ray_tracer{window.GetWindowSurface()};
    Scene scene{};

    Camera camera{};
    scene.RegisterCamera(&camera);

    Vector3<float> light_position{0.8, 0.3, -0.8};
    LightSource light{light_position, Color{1.0, 1.0, 1.0}};
    scene.RegisterLightSource(&light);

    Material material{Color{0.5, 0.0, 0.2}, Color{0.5, 0.3, 0.0}, 200};
    Material far_wall_material{Color{0.1, 0.1, 0.1}, Color{0.1, 0.1, 0.1}, 200};
    Material wall_material{Color{0.2, 0.2, 0.2}, Color{0.2, 0.2, 0.2}, 200};

    Sphere sphere{Vector3<float>{0.5, 0.0, 0.0}, 0.4, &material};
    scene.RegisterPrimitive(&sphere);

    Surface far{Vector3<float>{1.f, 0.f, 0.f}, Vector3<float>{-1.f, 0.f, 0.f}, &far_wall_material};
    scene.RegisterPrimitive(&far);

    Surface left{Vector3<float>{0.f, 1.f, 0.f}, Vector3<float>{0.f, -1.f, 0.f}, &wall_material};
    scene.RegisterPrimitive(&left);

    Surface right{Vector3<float>{0.f, -1.f, 0.f}, Vector3<float>{0.f, 1.f, 0.f}, &wall_material};
    scene.RegisterPrimitive(&right);

    Surface top{Vector3<float>{0.f, 0.f, -1.f}, Vector3<float>{0.f, 0.f, 1.f}, &wall_material};
    scene.RegisterPrimitive(&top);

    Surface bottom{Vector3<float>{0.f, 0.f, 1.f}, Vector3<float>{0.f, 0.f, -1.f}, &wall_material};
    scene.RegisterPrimitive(&bottom);

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

        float x = light_position.x;
        float y = light_position.y;
        light_position.x =   x * kCos + y * kSin;
        light_position.y = - x * kSin + y * kCos;
        light.SetWorldPosition(light_position);
    }

    return 0;
}
