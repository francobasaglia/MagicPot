#include <MagicPot.h>

#define DEBUG_BAUDIOS 9600
#define POTENTIOMETER_PIN A0

MagicPot potentiometer(POTENTIOMETER_PIN);

void setup()
{
	Serial.begin(DEBUG_BAUDIOS);

	potentiometer.begin();
}

void loop()
{
	potentiometer.read();

	Serial.println(String("Raw value: ") + potentiometer.getRawValue());
}
