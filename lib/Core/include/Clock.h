#ifndef CORE_CLOCK_H
#define CORE_CLOCK_H

#include <memory>
#include <chrono>

class Clock {
    public:
        Clock()=delete;
        Clock(unsigned int clockFreq);
        unsigned int getClockFreq();
        static Clock* instance();
    protected:
        unsigned int clockFreq;
    private:
        static std::unique_ptr<Clock> self_;
};


#endif