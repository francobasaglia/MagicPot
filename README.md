# MagicPot: An Arduino Library for Reading Potentiometer Values
[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](http://doge.mit-license.org)

MagicPot is an Arduino library that provides a simple and straightforward way to read the values of potentiometers. It is designed to work with any microcontroller board that has an analog-to-digital converter (ADC), including both Arduino and ESP boards.

## Features
* Compatible with both 10-bit and 12-bit resolution ADC
* Supports any potentiometer-based input device
* Easy to use and integrate into any project
* Supports callback functions for real-time updates
* Includes example sketches to help you get started quickly

MagicPot is highly customizable, allowing you to tailor it to your specific needs. With its support for both 10-bit and 12-bit resolution ADC, you can easily configure MagicPot to work with your particular input device. Additionally, you can adjust the sensitivity of the potentiometer readings and map the values to suit your project's requirements. The library is designed to be user-friendly, with straightforward functions that are easy to integrate into any project, whether you're working on a hobby project or a commercial application.

If you're new to MagicPot, the included example sketches will help you get started quickly and easily.

## Installation
We recommend using the latest version of the MagicPot library. The easiest way to install it is by using the Arduino Library Manager. However, you can also install it manually by downloading it from the [releases page](https://github.com/francobasaglia/MagicPot/releases).

### Using Arduino IDE and Arduino Library Manager
Follow these steps to install MagicPot using the Arduino Library Manager:

1. Open the Arduino IDE.
2. From the menu, go to **Sketch -> Include Library -> Manage Libraries...**
3. In the Library Manager search bar, type "MagicPot".
4. Click on the MagicPot library to open its details page.
5. Check that the installed version is the latest. If not, click the "Update" button to install the latest version.
6. Click the "Install" button to install the library.

### Manual Installation
Follow these steps to install MagicPot manually:

1. Download the MagicPot library from the [releases page](https://github.com/francobasaglia/MagicPot/releases).
2. Extract the library to your Arduino or ESP's libraries folder. The location of this folder depends on your operating system:
    * **Windows:** Documents/Arduino/libraries/
    * **MacOS:** Documents/Arduino/libraries/
    * **Linux:** ~/Arduino/libraries/
3. Restart the Arduino IDE or ESP platform if it was running during installation.

### After Installation
Once the installation is complete, you can include the MagicPot library in your sketch by adding the following line at the top of your code:

```cpp
#include <MagicPot.h>
```

This will allow you to access the MagicPot functions and use them in your project. If you're using the Arduino IDE, you can find examples of how to use the library in the **File -> Examples -> MagicPot** menu. If you're not using the Arduino IDE, you can find the examples in the **examples** folder of the MagicPot library directory. These examples demonstrate how to read potentiometer values and use the library's features in your own projects.

## Documentation
### Create an instance
As first step to use the library, you have to create a new instance of **MagicPot**.

```cpp
#include <MagicPot.h>

#define POTENTIOMETER_PIN A0

MagicPot potentiometer(POTENTIOMETER_PIN);
```
| Argument | Data type | Description |
|-|-|-|
| pin | `uint8_t` | Potentiometer input pin. |
| minRead | `uint16_t` | [Optional] Min mapped value. Default is `0`. |
| maxRead | `uint16_t` | [Optional] Max mapped value. Default is `MAX_RAW_VALUE_DEFAULT`. |
| maxRawRead | `uint16_t` | [Optional] Reference to max readable value. Default is `MAX_RAW_VALUE_DEFAULT`, and it corresponds to 10 bits resolution boards. You may need to change that, as it is shown on [this example]((../main/examples/MapReading_ESP32/MapReading_ESP32.ino)). |

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
The callback function should be setted on `setup` function, as is shown on [this example](../main/examples/MapReadingAndCallback/MapReadingAndCallback.ino).
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

### Complete list of methods
| Method | Description |
| ------ | ----------- |
| `MagicPot(uint8_t pin, uint16_t minRead = 0, uint16_t maxRead = MAX_RAW_VALUE_DEFAULT, uint16_t maxRawRead = MAX_RAW_VALUE_DEFAULT)` | Constructor for the MagicPot class. Initializes a new instance of the MagicPot class with the specified pin, minimum read value, maximum read value, and maximum raw read value. |
| `begin()` | Initializes the library. This method must be called before using any other method. |
| `onChange(callback_fn onChangeCallback, bool emitEvent = true)` | Sets the callback function to be called when the value of the potentiometer changes. The second parameter, `emitEvent`, controls whether the callback is called immediately after setting it or only when the potentiometer value changes. |
| `read(uint8_t sensitivity = 0)` | Reads the value of the potentiometer and maps it to the range specified by `minRead` and `maxRead`. The `sensitivity` parameter adjusts the sensitivity of the potentiometer. |
| `getValue()` | Returns the current value of the potentiometer, scaled to the range specified by `minRead` and `maxRead`. |
| `getRawValue()` | Returns the current raw value of the potentiometer, which is between 0 and the maximum raw value (either 1023 or 4095, depending on the resolution of the ADC). |

### Constants
The library also provides the following constants:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| `MAGIC_POT_MAX_RAW_VALUE_10B` | 1023 | The maximum raw value for a 10-bit ADC. |
| `MAGIC_POT_MAX_RAW_VALUE_12B` | 4095 | The maximum raw value for a 12-bit ADC. |
| `MAX_RAW_VALUE_DEFAULT` | `MAGIC_POT_MAX_RAW_VALUE_10B` | The default maximum raw value. |

Too know more about boards resolution works, please visit Arduino [Analog Read Documentation](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/).

## Examples sketches
[Raw reading](../main/examples/RawReading/RawReading.ino)

[Map reading](../main/examples/MapReading/MapReading.ino)

[Map reading (ESP32 / 12 bits boards)](../main/examples/MapReading_ESP32/MapReading_ESP32.ino)

[Map reading with callback](../main/examples/MapReadingAndCallback/MapReadingAndCallback.ino)

## License
[MIT](../main/LICENSE) © Franco Basaglia
