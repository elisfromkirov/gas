#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <SDL.h>

class Window {
private:
    static const uint32_t kDefaultXPos  = 0;
    static const uint32_t kDefaultYPos  = 0;

    static const uint32_t kDefaultWidth  = 800;
    static const uint32_t kDefaultHeight = 600;

public:
    explicit Window(const char* title);

    Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height);

    ~Window();

    void* GetNativeWindow();

private:
    SDL_Window* window_;
};

#endif // __WINDOW_HPP__
