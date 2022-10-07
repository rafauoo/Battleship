#include "include/Window.h"

WindowProperties::WindowProperties() {}

WindowProperties::WindowProperties(float heightOffset, float widthOffset):
heightOffset(heightOffset), widthOffset(widthOffset) {}

Window::Window() {
    videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    window = std::make_unique<sf::RenderWindow>(videoMode, "Battleshipss", sf::Style::Titlebar);
    window->setKeyRepeatEnabled(false);
    window->setFramerateLimit(60);
    windowProperties.window = window.get();
    windowProperties.widthOffset = 0.f;
    windowProperties.heightOffset = 0.f;
}

Window::~Window() {}

void Window::render() {}

sf::RenderWindow* Window::getWindow() {
    return window.get();
}

const uint Window::getHeight() {
    return WINDOW_HEIGHT;
}

const uint Window::getWidth() {
    return WINDOW_WIDTH;
}

std::vector<std::shared_ptr<Sprite>> Window::getSprites() {
    return sprites;
}

