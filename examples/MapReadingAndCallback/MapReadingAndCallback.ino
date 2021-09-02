#include <MagicPot.h>

#define DEBUG_BAUDIOS 9600
#define POTENTIOMETER_PIN A0
#define POTENTIOMETER_MIN_READ 0
#define POTENTIOMETER_MAX_READ 255

MagicPot potentiometer(POTENTIOMETER_PIN, POTENTIOMETER_MIN_READ, POTENTIOMETER_MAX_READ);

void setup()
{
	Serial.begin(DEBUG_BAUDIOS);

	potentiometer.begin();
	potentiometer.onChange(onPotentiometerChange);
}

void loop()
{
	potentiometer.read();
}

void onPotentiometerChange()
{
	Serial.println(String("Value: ") + potentiometer.getValue());
}
