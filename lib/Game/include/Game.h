#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include "../../Graphic/include/Window.h"
#include "../../Graphic/include/MenuWindow.h"
#include "../../Events/include/Event.h"
#include "../../Events/include/EventQueue.h"
class Clock;

class Game {
  public:
    Game() = delete;
    explicit Game(unsigned int clockFreq);
    void run();
    void redraw();
    void start();
    void initGraphic();
  protected:
    std::unique_ptr<Window> window;
    Clock* clock;
    EventQueue<Event> *eventQueue_;
    bool running = true;
};

#endif