#include "include/Game.h"
#include "../Core/include/Clock.h"
#include "../Graphic/include/Window.h"
#include "../Graphic/include/MenuWindow.h"

Game::Game(unsigned int clockFreq) {
    Clock::initialize(clockFreq);
    clock = Clock::instance();

}

void Game::run() {
    start();

    while (running == true) {
        clock->tick();


        redraw();
        sf::Event event;
        while (window->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == 0)
                {
                    for (std::shared_ptr<Sprite> spr: window->getSprites()) {
                        if (event.mouseButton.x > spr->x && event.mouseButton.x < spr->x + spr->scale * 35)
                            if (event.mouseButton.y > spr->y && event.mouseButton.y < spr->y + spr->scale * 15)
                            {
                                running = false;
                            }
                    }
                }
            }
        }


        clock->sleep();
    }
}

void Game::redraw() {
    window->getWindow()->clear(sf::Color::White);
    window->render();
    window->getWindow()->display();
}

void Game::start() {
    initGraphic();
}

void Game::initGraphic() {
    window = std::make_unique<MenuWindow>();
}