#include "include/Clock.h"

class SingletonNotInitializedException {};

Clock::Clock() {}

Clock::Clock(unsigned int clockFreq):
clockFreq(clockFreq) {}

unsigned int Clock::getClockFreq() {
    return clockFreq;
}

Clock *Clock::instance() {
    if(!self_){
        throw SingletonNotInitializedException();
    }

    return self_.get();
}