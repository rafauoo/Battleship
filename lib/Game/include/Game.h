#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include "../../Graphic/include/Window.h"
#include "../../Graphic/include/MenuWindow.h"
class Clock;

class Game {
  public:
    Game() = delete;
    explicit Game(unsigned int clockFreq);
    void run();
    void redraw();
    void start();
  protected:
    std::unique_ptr<MenuWindow> window;
    Clock* clock;
    bool running = true;
};

#endif