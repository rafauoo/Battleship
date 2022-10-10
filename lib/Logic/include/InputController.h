#ifndef LOGIC_INPUTCONTROLLER_H
#define LOGIC_INPUTCONTROLLER_H

#include <memory>
#include <SFML/Graphics.hpp>

class Event;

template <class E>
class EventQueue;

class InputController {
public:
    InputController() = delete;

    explicit InputController(sf::RenderWindow* window);

    void fetchInputEvent() const;

    sf::RenderWindow* window_;

    EventQueue<Event>* eventQueue_;
};


#endif