#include <algorithm>
#include <vector>

#include "platform.h"
#include "math.hpp"

void MatrixDump(const Math::Matrix<4>& matrix) {
    WRITE_LOG("%lg %lg %lg %lg\n%lg %lg %lg %lg\n%lg %lg %lg %lg\n%lg %lg %lg %lg\n",
              matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3],
              matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3],
              matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3],
              matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]);
}

void VectorDump(const Math::Vector<4>& vector) {
    WRITE_LOG("%lg\n%lg\n%lg\n%lg\n",
              vector[0],
              vector[1],
              vector[2],
              vector[3]);
}

class Renderer {
private:
    struct Mesh {
        Math::Vector<4> vertex1;
        Math::Vector<4> vertex2;
        Math::Vector<4> vertex3;

        Mesh(float buffer1[3], float buffer2[3], float buffer3[3]) {
            vertex1[0] = buffer1[0];
            vertex1[1] = buffer1[1];
            vertex1[2] = buffer1[2];
            vertex1[3] = 1.f;

            vertex2[0] = buffer2[0];
            vertex2[1] = buffer2[1];
            vertex2[2] = buffer2[2];
            vertex2[3] = 1.f;

            vertex3[0] = buffer3[0];
            vertex3[1] = buffer3[1];
            vertex3[2] = buffer3[2];
            vertex3[3] = 1.f;
        }
    };

public:
    /** направление движения камеры */
    enum Direction {
        Left,
        Right,
        Forward,
        Back,
        LeftRotation,
        RightRotation
    };

public:
    Renderer(Surface* surface) : surface(surface) {
        /** инициализация камеры */
        angle = 0.f;

        right[0] = 0.f;  
        right[1] = 1.f;  
        right[2] = 0.f;  
        
        up[0] = 0.f;
        up[1] = 0.f;
        up[2] = 1.f;

        forward[0] = 1.f;
        forward[1] = 0.f;
        forward[2] = 0.f;
        
        position[0] = 0.f;
        position[1] = 0.f;
        position[2] = 3.f;

        UpdateVeiwMatrix();

        /** инициализация двух (уже четырех) других штук */
        field_of_veiw = Math::pi/2.f;
        aspect_ratio = 0.75f;
        near_dist = 1.f;
        far_dist = 100.f;

        UpdateProjMatrix();

        /** выделим память под zbuffer */
        zbuffer = new float[surface->width * surface->height];

        /** ну и наш куб (надеюсь что получиться) */
        float a[] = { 0.2f,  0.2f,  0.2f};
        float b[] = {-0.2f,  0.2f,  0.2f};
        float c[] = {-0.2f, -0.2f,  0.2f};
        float d[] = { 0.2f, -0.2f,  0.2f};
        float e[] = { 0.2f,  0.2f, -0.2f};
        float f[] = {-0.2f,  0.2f, -0.2f};
        float g[] = {-0.2f, -0.2f, -0.2f};
        float h[] = { 0.2f, -0.2f, -0.2f};

        meshes.push_back(Mesh(a, b, d));
        meshes.push_back(Mesh(c, b, d));
        
        meshes.push_back(Mesh(a, e, d));
        meshes.push_back(Mesh(h, e, d));
        
        meshes.push_back(Mesh(d, h, c));
        meshes.push_back(Mesh(g, h, c));
        
        meshes.push_back(Mesh(c, g, b));
        meshes.push_back(Mesh(f, g, b));
        
        meshes.push_back(Mesh(e, a, f));
        meshes.push_back(Mesh(b, a, f));
        
        meshes.push_back(Mesh(e, h, f));
        meshes.push_back(Mesh(g, h, f));
    }

    ~Renderer() {
        delete[] zbuffer;
    }

    void Render() {
// WRITE_LOG("entry");
        float width = (float)surface->width/2.f;
        float height = (float)surface->height/2.f;

        Math::Matrix<4> matrix = proj_matrix * view_matrix;

        for (const Mesh& mesh : meshes) {
// WRITE_LOG("dbg");
            Math::Vector<4> proj1 = matrix * mesh.vertex1;
            proj1 /= proj1[3];
            proj1[0] = proj1[0] * width + width;
            proj1[1] = proj1[1] * height + height;
// VectorDump(proj1);
            Math::Vector<4> proj2 = matrix * mesh.vertex2;
            proj2 /= proj2[3];
            proj2[0] = proj2[0] * width + width;
            proj2[1] = proj2[1] * height + height;
// VectorDump(proj2);
            Math::Vector<4> proj3 = matrix * mesh.vertex3;
            proj3 /= proj3[3];
            proj3[0] = proj3[0] * width + width;
            proj3[1] = proj3[1] * height + height;
// VectorDump(proj3);
            DrawLine(proj1[0], proj1[1], proj2[0], proj2[1], 0x0000ff);
            DrawLine(proj1[0], proj1[1], proj3[0], proj3[1], 0x0000ff);
            DrawLine(proj2[0], proj2[1], proj3[0], proj3[1], 0x0000ff);
// WRITE_LOG("dbg");
        }

// WRITE_LOG("leave");
    }

    void CameraMove(Direction direction, float delta_time) {
        static const float speed = 0.05f/0.016667f;
        static const float omega = 0.05f/0.016667f;
 
        switch (direction) {
            case Left: {
                position[0] -= speed * delta_time;
            } break;
            case Right: {
                position[0] += speed * delta_time;
            } break;
            case Forward: {
                position[2] -= speed * delta_time;
            } break;
            case Back: {
                position[2] += speed * delta_time;
            } break;
            case LeftRotation: {
                angle -= omega * delta_time;

                forward[0] = cos(angle);
                forward[1] = sin(angle);

                right[0] = -sin(angle);
                right[1] = cos(angle);
            } break;
            case RightRotation: {
                angle += omega * delta_time;

                forward[0] = cos(angle);
                forward[1] = sin(angle);

                right[0] = -sin(angle);
                right[1] = cos(angle);
            } break;
            default: {}
        }

        UpdateVeiwMatrix();
    }

private:
    void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
        uint32_t* pixels = (uint32_t*)surface->pixels;

        int32_t x_delta = abs(x1 - x2);
        int32_t y_delta = abs(y1 - y2);

        int32_t x_sign = x1 < x2 ? 1 : -1;
        int32_t y_sign = y1 < y2 ? 1 : -1;

        int32_t error = x_delta - y_delta;

        if (0 <= y2 && y2 < surface->height && 0 <= x2 && x2 < surface->width) {
            pixels[y2 *  surface->width + x2] = color;
        }
        while (x1 != x2 || y1 != y2) {
            if (0 <= y1 && y1 < surface->height && 0 <= x1 && x1 < surface->width) {
                pixels[y1 *  surface->width + x1] = color;
            }

            int32_t error2 = error * 2;
            if(error2 > -y_delta) {
                error -= y_delta;
                x1 += x_sign;
            }
            if(error2 < x_delta) {
                error += x_delta;
                y1 += y_sign;
            }
        }
    }

    void _ver1_DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
        int32_t args_copy[] = {x1, y1, x2, y2};

        uint32_t* pixels = (uint32_t*)surface->pixels;

        int32_t x_delta = abs(x1 - x2);
        int32_t y_delta = abs(y1 - y2);

        int32_t x_sign = x1 < x2 ? 1 : -1;
        int32_t y_sign = y1 < y2 ? 1 : -1;

        int32_t error = x_delta - y_delta;

        uint32_t counter = 0;

        if (0 <= y2 && y2 < surface->height && 0 <= x2 && x2 < surface->width) {
            pixels[y2 *  surface->width + x2] = color;
        }
        while (x1 != x2 || y1 != y2) {
            if (0 <= y1 && y1 < surface->height && 0 <= x1 && x1 < surface->width) {
                pixels[y1 *  surface->width + x1] = color;
            }

            int32_t error2 = error * 2;
            if(error2 > -y_delta) {
                error -= y_delta;
                x1 += x_sign;
            }
            if(error2 < x_delta) {
                error += x_delta;
                y1 += y_sign;
            }

            ++counter;

            if (counter > 1000) {
                DebugDrawLine(args_copy[0], args_copy[1], args_copy[2], args_copy[3]);
                assert(!"endless loop");
            }
        }
    }
    /* алгоритм брезенхама
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    setPixel(x2, y2);
    while(x1 != x2 || y1 != y2) 
    {
        setPixel(x1, y1);
        int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
    */

    void DebugDrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
        WRITE_LOG("entry\n");

        WRITE_LOG("arg: x1 = %ld y1 = %ld x2 = %ld y2 = %ld\n", x1, y1, x2, y2);

        uint32_t* pixels = (uint32_t*)surface->pixels;

        int32_t x_delta = abs(x1 - x2);
        int32_t y_delta = abs(y1 - y2);

        WRITE_LOG("delta: x = %ld y = %ld\n", x_delta, y_delta);

        int32_t x_sign = x1 < x2 ? 1 : -1;
        int32_t y_sign = y1 < y2 ? 1 : -1;

        WRITE_LOG("sign: x = %ld y = %ld\n", x_sign, y_sign);

        int32_t error = x_delta - y_delta;

        WRITE_LOG("error: %ld\n", error);

        uint32_t counter = 0;

        while (x1 != x2 || y1 != y2) {
            WRITE_LOG("cur: x1 = %ld y1 = %ld x2 = %ld y2 = %ld error = %ld\n", x1, y1, x2, y2, error);

            int32_t error2 = error * 2;
            if(error2 > -y_delta) {
                error -= y_delta;
                x1 += x_sign;
            }
            if(error2 < x_delta) {
                error += x_delta;
                y1 += y_sign;
            }

            ++counter;

            if (counter > 1000) {
                break;
            }
        }

        WRITE_LOG("DebugDrawLine leave\n");
    }

    void UpdateVeiwMatrix() {
        view_matrix[0][0] = right[0];
        view_matrix[1][0] = right[1];
        view_matrix[2][0] = right[2];
        view_matrix[3][0] = 0.f;

        view_matrix[0][1] = up[0];
        view_matrix[1][1] = up[1];
        view_matrix[2][1] = up[2];
        view_matrix[3][1] = 0.f;
        
        view_matrix[0][2] = forward[0];
        view_matrix[1][2] = forward[1];
        view_matrix[2][2] = forward[2];
        view_matrix[3][2] = 0.f;

        view_matrix[0][3] = position[0];
        view_matrix[1][3] = position[1];
        view_matrix[2][3] = position[2];
        view_matrix[3][3] = 1.f;
    }

    void UpdateProjMatrix() {
        proj_matrix[0][0] = 2.f/tan(field_of_veiw/2.f);
        proj_matrix[1][0] = 0.f;
        proj_matrix[2][0] = 0.f;
        proj_matrix[3][0] = 0.f;

        proj_matrix[0][1] = 0.f;
        proj_matrix[1][1] = 2.f*aspect_ratio/tan(field_of_veiw/2.f);
        proj_matrix[2][1] = 0.f;
        proj_matrix[3][1] = 0.f;
        
        proj_matrix[0][2] = 0.f;
        proj_matrix[1][2] = 0.f;
        proj_matrix[2][2] = -1.f*(far_dist + near_dist)/(far_dist - near_dist);
        proj_matrix[3][2] = -1.f;

        proj_matrix[0][3] = 0.f;
        proj_matrix[1][3] = 0.f;
        proj_matrix[2][3] = -2.f*far_dist*near_dist/(far_dist - near_dist);
        proj_matrix[3][3] = 0.f;
    }

private:
    /** плоскость, на которой мы будем рисовать треутольники */
    Surface* surface;

    /** положение и направление камеры */
    float angle;

    Math::Vector<3> right;
    Math::Vector<3> up;
    Math::Vector<3> forward;
    Math::Vector<3> position;
    
    /** right_x  up_x  forward_x  position_x 
     *  right_y  up_y  forward_y  position_y
     *  right_z  up_z  forward_z  position_z
     *  0        0     0          1
     *
     * переход из мирового пространста в пространство камеры
     */
    Math::Matrix<4> view_matrix;

    /** данные необходимые для матрицы проекции */
    float field_of_veiw;
    float aspect_ratio;
    float near_dist;
    float far_dist;

    /** 2*near/(right-left)  0                    (right+left)/(right-left)  0
     *  0                    2*near/(top-bottom)  (top+bottom)/(top-bottom)  0
     *  0                    0                    -(far+near)/(far-near)     -2*near*far/(far-near)
     *  0                    0                    -1                         0
     *
     * переход из пространства камеры в пространство отсечения
     *
     *  2/tg(alpha/2)  0                0                       0
     *  0              2*a/tg(alpha/2)  0                       0
     *  0              0                -(far+near)/(far-near)  -2*near*far/(far-near)
     *  0              0                -1                      0
     *
     *
     * переход из пространства камеры в пространство отсечения, если вспомнить про то что такое
     * veiw frustrum (alpha) и aspect ratio (a)
     */
    Math::Matrix<4> proj_matrix;

    /** z-buffer глубины */
    float* zbuffer;

    /** треугольны меши, которые мы будем рендерить (пока без цвета и текстур) */
    std::vector<Mesh> meshes;
};


int WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int show_cmd) {
    InitPlatform(instance, "log/log.txt");

    const uint32_t default_x_pos = 0;
    const uint32_t default_y_pos = 0;

    const uint32_t default_width = 1200;
    const uint32_t default_height = 800;

    Window* window = NewWindow("renderer", default_x_pos, default_y_pos, default_width, default_height);
    Surface* surface = NewSurface(window);
    Renderer renderer(surface);

    LARGE_INTEGER frequency = {};
    LARGE_INTEGER begin_time = {};
    LARGE_INTEGER end_time = {};

    float delta_time =  0.016667f;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&begin_time);

    bool running = true;
    while (running) {
        /** обработка событий */
        Event event = {};
        while (GetEvent(&event)) {
            switch (event.type) {
                case KEYDOWN_EVENT: {
                    uint32_t key = event.keyboard_event.code;
                    switch (key) {
                        case KEY_A: {
                            renderer.CameraMove(Renderer::Direction::Left, delta_time);
                        } break;
                        case KEY_D: {
                            renderer.CameraMove(Renderer::Direction::Right, delta_time);
                        } break;
                        case KEY_W: {
                            renderer.CameraMove(Renderer::Direction::Forward, delta_time);
                        } break;
                        case KEY_S: {                            
                            renderer.CameraMove(Renderer::Direction::Back, delta_time);
                        } break;
                        case KEY_LEFT: {
                            renderer.CameraMove(Renderer::Direction::LeftRotation, delta_time);
                        } break;
                        case KEY_RIGHT: {
                            renderer.CameraMove(Renderer::Direction::RightRotation, delta_time);
                        } break;
                        case KEY_Q: {
                            running = false;
                        } break;
                        default: {}
                    }
                } break;
            }
        }

        /** рисуем куб (попытка 1223432423) */
        uint32_t* pixels = (uint32_t*)surface->pixels;
        for (size_t i = 0; i < surface->width * surface->height; ++i) {
            pixels[i] = 0x00ff00;
        }
        renderer.Render();
 
        /** call mySDL ahahahah */
        UpdateSurface(surface, window);

        /** время считаем */
        QueryPerformanceCounter(&end_time);

        delta_time = (float)(end_time.QuadPart - begin_time.QuadPart)/(float)frequency.QuadPart;

        /* while (delta_time < 0.016667f) {
            QueryPerformanceCounter(&end_time);
            delta_time = (float)(end_time.QuadPart - begin_time.QuadPart)/(float)frequency.QuadPart;
        } */

        // WRITE_LOG("dt %lg", delta_time);

        begin_time = end_time;
    }

    DeleteSurface(surface, window);
    DeleteWindow(window);

    QuitPlatform();
    return 0;
}

/*


const uint32_t vector3_size = 3;
typedef struct {
    float buffer[vector3_size];
} Vector3;

Vector3* NewDefaultVector3();
Vector3* NewVector3(float x, float y, float z);
void DeleteVector3(Vector3* vector3);

float Vector3DotProduct(const Vector3* lhs, const Vector3* rhs);
Vector3* Vector3CrossProduct(const Vector3* lhs, const Vector3* rhs);



const uint32_t vector4_size = 3;
typedef struct {
    float buffer[vector4_size];
} Vector4;

Vector4* NewDefaultVector4();
Vector4* NewVector4(float x, float y, float z, float w);
void DeleteVector4(Vector4* vector4);

float Vector4DotProduct(const Vector4* lhs, const Vector4* rhs);
Vector3* Vector4CrossProduct(const Vector4* lhs, const Vector4* rhs);


*/


/*
int32_t MinInt32(int32_t lhs, int32_t rhs) {
    return lhs < rhs ? lhs : rhs;
}

int32_t MaxInt32(int32_t lhs, int32_t rhs) {
    return lhs < rhs ? rhs : lhs;
}

int32_t AbsInt32(int32_t value) {
    return 0 < value ? value : -value;
}

void DrawLine(Surface* surface, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
    assert(surface);

    uint32_t* pixels = (uint32_t*)surface->pixels;

    int32_t x_delta = MaxInt32(x1, x2) - MinInt32(x1, x2);
    int32_t y_delta = MaxInt32(y1, y2) - MinInt32(y1, y2);

    int32_t x_sign = x1 < x2 ? 1 : -1;
    int32_t y_sign = y1 < y2 ? 1 : -1;

    int32_t error = x_delta - y_delta;

    pixels[y2 *  surface->width + x2] = color;
    while (x1 != x2 || y1 != y2) {
        pixels[y1 *  surface->width + x1] = color;
        
        if(error * 2 > -y_delta) {
            error -= y_delta;
            x1 += x_sign;
        }
        if(error * 2 < x_delta) {
            error += x_delta;
            y1 += y_sign;
        }
    }
}

void DrawScreen(Surface* surface, uint32_t color) {
    assert(surface);

    uint32_t* pixels = (uint32_t*)surface->pixels;
    for (size_t i = 0; i < surface->width * surface->height; ++i) {
        pixels[i] = color;
    }    
}

*/

// Renderer::Render
        /*
        Math::Matrix<4> matrix = proj_matrix;

        for (const Mesh& mesh : meshes) {
            Math::Vector<4> proj1 = matrix * mesh.vertex1;
            proj1 /= proj1[3];
            proj1[0] = 600.f + proj1[0] * 600.f;
            proj1[1] = 400.f + proj1[1] * 400.f;

            Math::Vector<4> proj2 = matrix * mesh.vertex2;
            proj2 /= proj2[3];
            proj2[0] = 600.f + proj2[0] * 600.f;
            proj2[1] = 400.f + proj2[1] * 400.f;
            
            Math::Vector<4> proj3 = matrix * mesh.vertex3;
            proj3 /= proj3[3];
            proj3[0] = 600.f + proj3[0] * 600.f;
            proj3[1] = 400.f + proj3[1] * 400.f;

            DrawLine(proj1[0], proj1[1], proj2[0], proj2[1], 0x0000ff);
            DrawLine(proj1[0], proj1[1], proj3[0], proj3[1], 0x0000ff);
            DrawLine(proj2[0], proj2[1], proj3[0], proj3[1], 0x0000ff);
        }
        */

// ice cube
        /*
        float a[] = { 0.2f,  0.2f,  0.2f - 2.f};
        float b[] = {-0.2f,  0.2f,  0.2f - 2.f};
        float c[] = {-0.2f, -0.2f,  0.2f - 2.f};
        float d[] = { 0.2f, -0.2f,  0.2f - 2.f};
        float e[] = { 0.2f,  0.2f, -0.2f - 2.f};
        float f[] = {-0.2f,  0.2f, -0.2f - 2.f};
        float g[] = {-0.2f, -0.2f, -0.2f - 2.f};
        float h[] = { 0.2f, -0.2f, -0.2f - 2.f};
        */
/*

void _1_DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
        int32_t args_copy[] = {x1, y1, x2, y2};

        uint32_t* pixels = (uint32_t*)surface->pixels;

        int32_t x_delta = abs(x1 - x2);
        int32_t y_delta = abs(y1 - y2);

        int32_t x_sign = x1 < x2 ? 1 : -1;
        int32_t y_sign = y1 < y2 ? 1 : -1;

        int32_t error = x_delta - y_delta;

        uint32_t counter = 0;

        if (0 <= y2 && y2 < surface->height && 0 <= x2 && x2 < surface->width) {
            pixels[y2 *  surface->width + x2] = color;
        }
        while (x1 != x2 || y1 != y2) {
            if (0 <= y1 && y1 < surface->height && 0 <= x1 && x1 < surface->width) {
                pixels[y1 *  surface->width + x1] = color;
            }

            if(error * 2 > -y_delta) {
                error -= y_delta;
                x1 += x_sign;
            }
            if(error * 2 < x_delta) {
                error += x_delta;
                y1 += y_sign;
            }

            ++counter;

            if (counter > 1000) {
                WRITE_LOG("Error: endless loop\n"
                          "\targument values: x1 = %ld, y1 = %ld, x2 = %ld, y2 = %ld\n"
                          "\tcurrent  values: x1 = %ld, y1 = %ld, x2 = %ld, y2 = %ld\n", 
                          args_copy[0], args_copy[1], args_copy[2], args_copy[3],
                          x1, y1, x2, y2);
                break;
            }
        }
    }

*/