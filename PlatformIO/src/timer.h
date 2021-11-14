#ifndef TIMER_H
#define TIMER_H


#include <stdint.h>


class Timer {
    private:
        uint32_t nextTick;
        uint16_t delay;
        bool ticked;
        bool isStarted = true; //autostart every timer to be backwards compatible with existing occasions

    public:
        Timer(uint16_t delay);
        const bool hasTicked();
        void reset();
        void start();
        void stop();
};


#endif
