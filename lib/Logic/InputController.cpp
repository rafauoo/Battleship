#include "include/InputController.h"
#include "../Events/include/EventQueue.h"
#include "../Events/include/Event.h"

InputController::InputController(sf::RenderWindow* window): window_(window){
    eventQueue_ = EventQueue<Event>::instance();
}

void InputController::fetchInputEvent() const {
    sf::Event event;
    window_->pollEvent(event);

    switch (event.type) {
        case sf::Event::KeyReleased: {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::KeyReleased,
                                                               event.key.code));
            break;
        }
        case sf::Event::KeyPressed: {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::KeyPressed,
                                                               event.key.code));
            break;
        }
        case sf::Event::MouseButtonPressed: {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::MouseLeftClick,
                                                               event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::MouseRightClick,
                                                               event.mouseButton.x, event.mouseButton.y));
            }
            break;
        }
        case sf::Event::MouseButtonReleased: {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::MouseLeftReleased,
                                                               event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::EventType::MouseRightReleased,
                                                               event.mouseButton.x, event.mouseButton.y));
            }
            break;
        }
        default: {
            eventQueue_->registerEvent(std::make_unique<Event>(Event::NullEvent));
            break;
        }
    }
}