#include "include/Sprite.h"


Sprite::Sprite(float x, float y, float scale, const std::string &filename):
x(x), y(y), scale(scale) {
    sprite = std::make_unique<sf::Sprite>();
    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile(filename);
    sprite->setTexture(*texture.get());
    sprite->setScale(scale, scale);
    sprite->move(x, y);
}