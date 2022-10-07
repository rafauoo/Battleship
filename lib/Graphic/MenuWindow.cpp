#include "include/MenuWindow.h"
#include "include/Sprite.h"

void MenuWindow::render() {
    unsigned int scale = 8;
    window->clear(sf::Color::Black);
    std::shared_ptr<Sprite> play = std::make_shared<Sprite>(WINDOW_WIDTH / 2 - (scale * 35) / 2, 50, scale, "../lib/Graphic/Textures/Buttons/play.png");
    std::shared_ptr<Sprite> settings = std::make_shared<Sprite>(WINDOW_WIDTH / 2 - (scale - 2)* 35 / 2, 100 + (scale)* 15, scale - 2, "../lib/Graphic/Textures/Buttons/settings.png");
    std::shared_ptr<Sprite> quit = std::make_shared<Sprite>(WINDOW_WIDTH / 2 - (scale - 2)* 35 / 2, 120 + (scale)* 15 + (scale - 2)* 15, scale - 2, "../lib/Graphic/Textures/Buttons/quit.png");
    sprites.push_back(play);
    sprites.push_back(settings);
    sprites.push_back(quit);
    window->draw(*play->sprite.get());
    window->draw(*settings->sprite.get());
    window->draw(*quit->sprite.get());
}

void MenuWindow::drawSprites() {
    return;
}