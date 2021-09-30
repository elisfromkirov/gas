#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "WindowSurface.hpp"

class Window {
public:
    Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height);

    ~Window();

    WindowSurface GetWindowSurface();

    void UpdateWindowSurface();

private:
    SDL_Window*   window_;

    const char*   title_;
    uint32_t      x_pos_;
    uint32_t      y_pos_;
    uint32_t      width_;
    uint32_t      height_;

    SDL_Surface* surface_;
};

#endif // __WINDOW_HPP__
