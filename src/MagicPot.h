#ifndef MagicPot_h
#define MagicPot_h

#include <Arduino.h>

/**
 * Define max raw read from potentiometer. Setting default for 10 bits boards.
 * 
 * See more: https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
 */
#define MAGIC_POT_MAX_RAW_VALUE_10B     1023
#define MAGIC_POT_MAX_RAW_VALUE_12B     4095
#define MAX_RAW_VALUE_DEFAULT           (MAGIC_POT_MAX_RAW_VALUE_10B)

class MagicPot
{
	public:
		typedef void (*callback_fn)();
		MagicPot(uint8_t pin, uint16_t minRead = 0, uint16_t maxRead = MAX_RAW_VALUE_DEFAULT, uint16_t maxRawRead = MAX_RAW_VALUE_DEFAULT): pin(pin), minRead(minRead), maxRead(maxRead), maxRawRead(maxRawRead) {};
		void begin();
		void onChange(callback_fn onChangeCallback, bool emitEvent = true);
		void read(uint8_t sensitivity = 0);
		uint16_t getValue();
		uint16_t getRawValue();

	private:
		uint8_t pin;
		uint16_t minRead;
		uint16_t maxRead;
		uint16_t maxRawRead;
		callback_fn onChangeCallback;
		uint16_t value;
		uint16_t rawValue;
};

#endif
