#include <SFML/Graphics.hpp>
#include "lib/Logic/include/Menu.h"
#include "lib/Graphic/include/MenuWindow.h"
int main()
{
    std::unique_ptr<MenuWindow> window = std::make_unique<MenuWindow>();
    while (window->getWindow()->isOpen()) {
        sf::Event event;
        while (window->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return 0;
            }
        }
        window->getWindow()->clear(sf::Color::White);
        window->render();
        window->getWindow()->display();
    }
}