#include "Window.hpp"

Window::Window(const char* title)
    : Window(title, kDefaultXPos, kDefaultYPos, kDefaultWindowWidth, kDefaultWindowHeight) {}


Window::Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height)
    : window_{nullptr}, title_{title}, x_pos_{x_pos}, y_pos_{y_pos}, width_{width}, 
      height_{height}, surface_{nullptr} {
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, SDL_WINDOW_SHOWN);
    assert(window_ != nullptr);

    surface_ = SDL_GetWindowSurface(window_);
    assert(surface_ != nullptr);
}

Window::~Window() {
    assert(window_  != nullptr);
    assert(surface_ != nullptr);

    SDL_DestroyWindow(window_);
}

WindowSurface Window::GetWindowSurface() {
    assert(window_  != nullptr);
    assert(surface_ != nullptr);

    return WindowSurface{static_cast<uint32_t*>(surface_->pixels), width_, height_};
}

void Window::UpdateWindowSurface() {
    assert(window_  != nullptr);
    assert(surface_ != nullptr);

    SDL_UpdateWindowSurface(window_);
}

const char* Window::GetTitle() const {
    return title_;
}

void Window::SetTitle(const char* title) {
    title_ = title;
    SDL_SetWindowTitle(window_, title_);
}