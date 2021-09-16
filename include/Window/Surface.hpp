#ifndef __SURFACE_HPP__
#define __SURFACE_HPP__

#include <cstdint>

#include "Window.hpp"

class Surface {
public:
    Surface(Window& window);
    
    ~Surface();

    uint32_t* operator[](uint32_t y);

    const uint32_t* operator[](uint32_t y) const;

    void Update();

    uint32_t GetWidth() const;
    
    uint32_t GetHeight() const;

private:
    SDL_Window* window_;
    SDL_Surface* surface_;
};

#endif // __SURFACE_HPP__
