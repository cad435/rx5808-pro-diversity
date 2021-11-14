#ifndef STATE_SCREENSAVER_H
#define STATE_SCREENSAVER_H


#include "state.h"
#include "timer.h"
#include "../settings/settings.h"


namespace StateMachine {
    class ScreensaverStateHandler : public StateMachine::StateHandler {
        private:
            Timer displaySwapTimer = Timer(SCREENSAVER_DISPLAY_CYCLE * 1000);
            bool showLogo = false;
            uint8_t DrawState = 0;
            /*
                DrawState:
                    0: Logo
                    1: Channel & MHz
                    2: Battery Voltage
            */
            
            float Voltage = 0; //used to determine Battery-Voltage

        public:
            void onEnter();
            void onUpdate();

            void onInitialDraw();
            void onUpdateDraw();

            void onButtonChange(Button button, Buttons::PressType pressType);
    };
}


#endif
