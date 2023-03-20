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

## Examples sketches
[Raw reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/RawReading/RawReading.ino)

[Map reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading/MapReading.ino)

[Map reading (ESP32 / 12 bits boards)](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading_ESP32/MapReading_ESP32.ino)

[Map reading with callback](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReadingAndCallback/MapReadingAndCallback.ino)
