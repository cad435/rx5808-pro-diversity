#ifndef _VBAT_MEAS_H_
#define _VBAT_MEAS_H_

#include <Arduino.h>
#include <stdint.h>
#include "settings/settings.h"


namespace Vbat_Measure {
    
    extern float BatteryVoltage;

    

    void update();
    float getBatteryVoltage();



}

#endif