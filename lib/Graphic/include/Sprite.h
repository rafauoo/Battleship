#ifndef GRAPHIC_SPRITE_H
#define GRAPHIC_SPRITE_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>



class Sprite {
    public:
        float x, y, scale;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
        Sprite(float x, float y, float scale, const std::string &filename);
};
#endif