#include "MagicPot.h"

MagicPot::MagicPot(uint8_t pin)
{
    this->pin = pin;
    this->value = 0;
}

void MagicPot::read()
{
    this->value = analogRead(this->pin);
}

uint16_t MagicPot::getValue()
{
    return this->value;
}
