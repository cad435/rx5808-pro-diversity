#include <Arduino.h>
#include "Vbat_Measure.h"
#include "timer.h"


namespace Vbat_Measure {

    float BatteryVoltage = 3.3;
    bool beep = true;

    Timer Beep_Timer = Timer(1 * 1000);

    void update()
    {
        BatteryVoltage = analogRead(PIN_VBAT);
        //scale ADC reading roughly to a voltage
        BatteryVoltage = BatteryVoltage / VBAT_DIVISOR;

        //if warning voltage, beep with timer frequency
        if (BatteryVoltage <= WARNING_VOLTAGE)
        {
            Beep_Timer.start();
            if (Beep_Timer.hasTicked())
            {
                digitalWrite(PIN_BUZZER, beep);
                beep = !beep;
                Beep_Timer.reset();//reset the timer, so it can tick again.
            }

        }
        //if no warning, just turn off the beeper at the next tick
        else if (Beep_Timer.hasTicked())
        {
            digitalWrite(PIN_BUZZER, LOW);
            Beep_Timer.stop();//stop the timer to prevent any overflow-beeps
        }      

    }

    float getBatteryVoltage()
    {
        return BatteryVoltage;
    }
}