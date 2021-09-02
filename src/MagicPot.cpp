#include "MagicPot.h"

void MagicPot::begin()
{
	this->onChangeCallback = nullptr;
	this->value = 0;
	this->rawValue = 0;
}

void MagicPot::onChange(callback_fn onChangeCallback, bool emitEvent)
{
	this->onChangeCallback = onChangeCallback;

	if (emitEvent)
		this->onChangeCallback();
}

void MagicPot::read(uint8_t sensitivity)
{
	this->rawValue = analogRead(this->pin);

	uint16_t value = map(this->rawValue, 0, this->maxRawRead, this->minRead, this->maxRead);

	if (sensitivity == 0 && value != this->value)
	{
		this->value = value;
		if (this->onChangeCallback)
			this->onChangeCallback();
	}
	else if (abs(value - this->value) > sensitivity)
	{
		this->value = value;
		if (this->onChangeCallback)
			this->onChangeCallback();
	}
	else if (value < sensitivity && this->value != this->minRead)
	{
		this->value = minRead;
		if (this->onChangeCallback)
			this->onChangeCallback();
	}
	else if (value + sensitivity > maxRead && this->value != this->maxRead)
	{
		this->value = this->maxRead;
		if (this->onChangeCallback)
			this->onChangeCallback();
	}
}

uint16_t MagicPot::getValue()
{
	return this->value;
}

uint16_t MagicPot::getRawValue()
{
	return this->rawValue;
}
