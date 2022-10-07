#include "include/MenuWindow.h"

void MenuWindow::render() {
    unsigned int scale = 8;
    window->clear(sf::Color::Black);
    sf::Texture play_button, settings_button, quit_button;
    play_button.loadFromFile("../lib/Graphic/Textures/Buttons/play.png");
    settings_button.loadFromFile("../lib/Graphic/Textures/Buttons/settings.png");
    quit_button.loadFromFile("../lib/Graphic/Textures/Buttons/quit.png");
    sf::Sprite play, settings, quit;
    play.setTexture(play_button);
    play.scale(scale, scale);
    play.move(sf::Vector2f(WINDOW_WIDTH / 2 - (scale * 35) / 2, 50));
    settings.setTexture(settings_button);
    settings.scale(scale - 2, scale - 2);
    settings.move(sf::Vector2f(WINDOW_WIDTH / 2 - (scale - 2)* 35 / 2, 100 + (scale)* 15));
    quit.setTexture(quit_button);
    quit.scale(scale - 2, scale - 2);
    quit.move(sf::Vector2f(WINDOW_WIDTH / 2 - (scale - 2)* 35 / 2, 120 + (scale)* 15 + (scale - 2)* 15));
    window->draw(play);
    window->draw(settings);
    window->draw(quit);
}