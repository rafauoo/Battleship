#ifndef GAME_GAME_H
#define GAME_GAME_H

class Clock;

class Game {
  public:
    Game();
    Game(unsigned int clockFreq);
  protected:
    Clock* clock;
};

#endif