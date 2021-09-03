# MagicPot
[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](http://doge.mit-license.org)

Arduino library for reading values easily from potentiometers.


## Description
**MagicPot** is a small Arduino Library for read values easily from potentiometers. It has several configurations in order to:
* Obtain mapped *value* on a desire range.
* Work with 10 or 12 bits resolution boards.
* Define *callback function* whenever the read from the potentiometer changes.
* Define *sensitivity* value at reading time - useful for noisy potentiometers.



## Installation
You can install this library using **Arduino Library Manager**, or downloading the [latest release](https://github.com/francobasaglia/MagicPot/releases) from GitHub repository.



## Documentation
### Include the library on your project
Once the library is installed, include it on any file where you're going to use it.

```cpp
#include <MagicPot.h>
```


### Constants
There is 3 values used as constants on this library:
```cpp
#define MAGIC_POT_MAX_RAW_VALUE_10B     1023
#define MAGIC_POT_MAX_RAW_VALUE_12B     4095
#define MAX_RAW_VALUE_DEFAULT           (MAGIC_POT_MAX_RAW_VALUE_10B)
```

Too know more about boards resolution works, please visit [Arduino Analog Read Documentation](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/).


### Create an instance
In order to use the library, you have to create a new instance of **MagicPot**. Your code should be something like this:

```cpp
#include <MagicPot.h>

#define POTENTIOMETER_PIN A0

MagicPot potentiometer(POTENTIOMETER_PIN);
```

The class constructor could receive up to 4 arguments, that are going to be used for mapping the raw values. This is the list of arguments:

| Argument | Data type | Description |
|-|-|-|
| pin | `uint8_t` | Potentiometer input pin. |
| minRead | `uint16_t` | [Optional] Min mapped value. Default is `0`. |
| maxRead | `uint16_t` | [Optional] Max mapped value. Default is `MAX_RAW_VALUE_DEFAULT`. |
| maxRawRead | `uint16_t` | [Optional] Reference to max readable value. Default is `MAX_RAW_VALUE_DEFAULT`, and it corresponds to 10 bits resolution boards. You may need to change that, as it is shown on [this example]((https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading_ESP32/MapReading_ESP32.ino)). |


### Initialize potentiometer
You have to initialize the potentiometer with the `begin` method. This usually happen within the `setup` function.

```cpp
void setup()
{
    potentiometer.begin();
}
```


### Update potentiometer value
You have to update the potentiometer value with the `read` method. Is recommended to do this within the `loop` function.
The `read` method could receive a `sensitivity` parameter, You may have a noisy potentiometer, in order to prevent inconsistent value updates.

```cpp
void loop()
{
    potentiometer.read();
    // Or with sensitivity
    potentiometer.read(2);
}
```

| Argument | Data type | Description |
|-|-|-|
| sensitivity | `uint8_t` | [Optional] Potentiometer sensitivity. This value is going to be applied over mapped reading. Default is `0`. |


### Value change callback
You could set up a function to be executed whenever the potentiometer change.
The callback function should be setted on `setup` function, as is shown on [this example](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReadingAndCallback/MapReadingAndCallback.ino).
The use of change callback is **optional**.

```cpp
#include <MagicPot.h>

#define POTENTIOMETER_PIN A0

MagicPot potentiometer(POTENTIOMETER_PIN);

void setup()
{
    potentiometer.begin();
    potentiometer.onChange(onPotentiometerChange);
}

void loop()
{
    potentiometer.read();
}

void onPotentiometerChange()
{
    // Potentiometer value changed!
}
```

| Argument | Data type | Description |
|-|-|-|
| onChangeCallback | `callback_fn` | Function to be executed when potentiometer value change. |
| emitEvent | `bool` | [Optional] Emit change event when change callback is setted up. Default value is `true`. |

### Reading potentiometer values
**MagicPot** retains both raw reads and mapped reads. You can access them using `getValue` and `getRawValue` methods whenever you need to. Both returns a number of type `uint16_t`.

```cpp
void loop()
{
    potentiometer.read();

    int value = potentiometer.getValue();
}
```



## Complete list of methods
```cpp
void begin();
void onChange(callback_fn onChangeCallback, bool emitEvent = true);
void read(uint8_t sensitivity = 0);
uint16_t getValue();
uint16_t getRawValue();
```



## Examples
[Raw reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/RawReading/RawReading.ino)

[Map reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading/MapReading.ino)

[Map reading (ESP32 / 12 bits boards)](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading_ESP32/MapReading_ESP32.ino)

[Map reading with callback](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReadingAndCallback/MapReadingAndCallback.ino)
