#ifndef MagicPot_h
#define MagicPot_h

#include <Arduino.h>

class MagicPot
{
    public:
        typedef void (*callback_t)();
        MagicPot(uint8_t pin);
        void read();
        uint16_t getValue();

    private:
        uint8_t pin;
        uint16_t value;
};

#endif
