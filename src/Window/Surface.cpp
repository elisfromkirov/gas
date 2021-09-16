#include <cassert>
#include <cstdint>

#include "Surface.hpp"

Surface::Surface(Window& window) {
    window_ = (SDL_Window*)window.GetNativeWindow();
    assert(window_);

    surface_ = SDL_GetWindowSurface(window_);
    assert(surface_);
}
    
Surface::~Surface() {}

uint32_t* Surface::operator[](uint32_t y) {
    assert(window_);
    assert(surface_);
    assert(surface_->pixels);
    assert(y < (uint32_t) surface_->h);

    return (uint32_t*)surface_->pixels + y * surface_->w;
}

const uint32_t* Surface::operator[](uint32_t y) const {
    assert(window_);
    assert(surface_);
    assert(surface_->pixels);
    assert(y < (uint32_t) surface_->h);

    return (uint32_t*)surface_->pixels + y * surface_->w;
}

void Surface::Update() {
    assert(window_);
    assert(surface_);

    SDL_UpdateWindowSurface(window_);
}

uint32_t Surface::GetWidth() const {
    assert(window_);
    assert(surface_);

    return surface_->w;
}
    
uint32_t Surface::GetHeight() const {
    assert(window_);
    assert(surface_);

    return surface_->h;
}
