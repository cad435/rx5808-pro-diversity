#include <Arduino.h>
#include "timer.h"


Timer::Timer(uint16_t delay) {
    this->delay = delay;
    this->nextTick = millis() + this->delay;
    this->ticked = false;
}

const bool Timer::hasTicked() {
    bool hasTicked = false;
    if (this->ticked)
        hasTicked = true;

    else if (millis() >= this->nextTick) {
        this->ticked = true;
        hasTicked = true;
    }
    
    
    if (isStarted)
    {
        return hasTicked;
    }
    return false;
}

void Timer::reset() {
    this->nextTick = millis() + this->delay;
    this->ticked = false;
}

void Timer::start()
{
    isStarted = true;
}
void Timer::stop()
{
    isStarted = false;
}
