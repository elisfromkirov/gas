#include "Window.hpp"

#include <cassert>
#include <cstdint>

Window::Window(const char* title) : Window(title, kDefaultXPos, kDefaultYPos, kDefaultWidth, kDefaultHeight) {}

Window::Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height) {
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, SDL_WINDOW_SHOWN);
    assert(window_);
}

Window::~Window() {
    assert(window_);

    SDL_DestroyWindow(window_);
}

void* Window::GetNativeWindow() {
    return (SDL_Window*)window_;
}
