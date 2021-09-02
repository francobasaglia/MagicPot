#include <MagicPot.h>

#define DEBUG_BAUDIOS 115200
#define POTENTIOMETER_PIN A0
#define POTENTIOMETER_MIN_READ 0
#define POTENTIOMETER_MAX_READ 255

MagicPot potentiometer(POTENTIOMETER_PIN, POTENTIOMETER_MIN_READ, POTENTIOMETER_MAX_READ, MAGIC_POT_MAX_RAW_VALUE_12B);

void setup()
{
	Serial.begin(DEBUG_BAUDIOS);

	potentiometer.begin();
}

void loop()
{
	potentiometer.read();

	Serial.println(String("Value: ") + potentiometer.getValue());
}
