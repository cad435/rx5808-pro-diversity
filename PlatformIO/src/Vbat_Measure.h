#ifndef _VBAT_MEAS_H_
#define _VBAT_MEAS_H_

#include <Arduino.h>
#include <stdint.h>
#include "settings/settings.h"


namespace Vbat_Measure {
    
    float BatteryVoltage = 3.3; //V
    void update()
    {
        BatteryVoltage = analogRead(PIN_VBAT);
        //scale ADC reading roughly to a voltage
        BatteryVoltage = BatteryVoltage / VBAT_DIVISOR;
    }
    float getBatteryVoltage()
    {
        return BatteryVoltage;
    }





#endif