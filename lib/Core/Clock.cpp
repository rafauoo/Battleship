#include "include/Clock.h"
#include <thread>

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

void Clock::tick() {
    last_tick_ = std::chrono::steady_clock::now();
}

void Clock::sleep() {
    std::this_thread::sleep_for(last_tick_ + interval_ - std::chrono::steady_clock::now());
}