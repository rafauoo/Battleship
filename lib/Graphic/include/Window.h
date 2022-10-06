#ifndef GRAPHIC_WINDOW_H
#define GRAPHIC_WINDOW_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

struct WindowProperties
{
    float heightOffset;
    float widthOffset;
    WindowProperties(float heightOffset, float widthOffset);
    WindowProperties();
    sf::RenderWindow* window;
};

class Window
{
  protected:
    const uint WINDOW_HEIGHT = 1000;
    const uint WINDOW_WIDTH = 1000;
    sf::VideoMode videoMode;
    WindowProperties windowProperties;
    std::vector<std::shared_ptr<Window>> children;
  public:
    std::unique_ptr<sf::RenderWindow> window;
    sf::RenderWindow* getWindow();
    virtual void render()=0;
    Window();
    Window(const WindowProperties& windowProperties);
    virtual ~Window();
};


#endif