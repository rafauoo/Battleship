#ifndef GRAPHIC_WINDOW_H
#define GRAPHIC_WINDOW_H

#include <SFML/System.hpp>
#include "Sprite.h"
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
    const uint WINDOW_HEIGHT = 480;
    const uint WINDOW_WIDTH = 640;
    sf::VideoMode videoMode;
    WindowProperties windowProperties;
    std::vector<std::shared_ptr<Window>> children;
    std::vector<std::shared_ptr<Sprite>> sprites;
  public:
    std::unique_ptr<sf::RenderWindow> window;
    sf::RenderWindow* getWindow();
    virtual void render()=0;
    const uint getHeight();
    const uint getWidth();
    std::vector<std::shared_ptr<Sprite>> getSprites();
    Window();
    Window(const WindowProperties& windowProperties);
    virtual ~Window();
};


#endif