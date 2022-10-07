#include "include/Clock.h"

class SingletonNotInitializedException {};


Clock::Clock(unsigned int freq) {
    interval_ = std::chrono::nanoseconds(1000000000) / freq;
}

std::unique_ptr<Clock> Clock::self_ = nullptr;

void Clock::initialize(unsigned int freq) {
    self_ = std::unique_ptr<Clock>(new Clock(freq));
}

Clock *Clock::instance() {
    if(!self_){
        throw SingletonNotInitializedException();
    }

    return self_.get();
}