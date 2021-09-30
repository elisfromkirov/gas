#include "WindowSurface.hpp"

WindowSurface::WindowSurface(uint32_t* pixels, uint32_t width, uint32_t height)
    : pixels_{pixels}, width_{width}, height_{height} {}

WindowSurface::~WindowSurface() {}

uint32_t* WindowSurface::operator[](uint32_t y) {
    assert(pixels_ != nullptr);

    return pixels_ + y * width_;
}

const uint32_t* WindowSurface::operator[](uint32_t y) const {
    assert(pixels_ != nullptr);

    return pixels_ + y * width_;
}

uint32_t WindowSurface::GetWidth() const {
    return width_;
}
    
uint32_t WindowSurface::GetHeight() const {
    return height_;
}
