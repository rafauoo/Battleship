#ifndef CORE_CLOCK_H
#define CORE_CLOCK_H

#include <memory>
#include <chrono>

class Clock {
    public:
        Clock()=delete;
        Clock(const Clock&)=delete;
        Clock operator=(const Clock&)=delete;
        unsigned int getClockFreq();
        static Clock* instance();
        static void initialize(unsigned int frequency);
    private:
        std::chrono::nanoseconds interval_{};
        explicit Clock(unsigned int frequency);
        static std::unique_ptr<Clock> self_;
};


#endif