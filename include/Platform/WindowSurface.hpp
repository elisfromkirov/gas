#ifndef __WINDOW_SURFACE_HPP__
#define __WINDOW_SURFACE_HPP__

#include <cstdint>
#include <cassert>

class WindowSurface {
public:
    ~WindowSurface();

    uint32_t* operator[](uint32_t y);

    const uint32_t* operator[](uint32_t y) const;

    uint32_t GetWidth() const;
    
    uint32_t GetHeight() const;

private:
    WindowSurface(uint32_t* pixels, uint32_t width, uint32_t height);

private:
    uint32_t* pixels_;
    uint32_t  width_;
    uint32_t  height_;

    friend class Window;
};

#endif // __WINDOW_SURFACE_HPP__
