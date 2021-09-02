# MagicPot

[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](http://doge.mit-license.org)

Arduino library for read values easily from potentiometers.

## Description

**MagicPot** is a little Arduino Library for read values easily from potentiometers. It has several configurations in order to:
* Obtain a mapped *value* on a desire range.
* Work with 10 or 12 bits resolution boards.
* Define a *callback function* whenever the read from the potentiometer changes.
* Define a *sensitivity* value at reading time - usefully for noisy potentiometers.

## Installation
You can install this library using **Arduino Library Manager**, or downloading the [latest release](https://github.com/francobasaglia/MagicPot/releases) from GitHub repository

## Examples
[Raw reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/RawReading/RawReading.ino)
[Map reading](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading/MapReading.ino)
[Map reading (ESP32 / 12 bits boards)](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReading_ESP32/MapReading_ESP32.ino)
[Map reading with callback](https://github.com/francobasaglia/MagicPot/blob/main/examples/MapReadingAndCallback/MapReadingAndCallback.ino)
