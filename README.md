# Arduino Lib

This repository is destined to development of libraries for Arduino, especially Uno and Mega 2560 models.

> **NOTE:** In 2024/10/14 the repository was revised and passed to a small revisions on each development branches to make a better development environment. Now all development branches will be merged first on `Development` branch and than it will be merged to `master`.

> **NOTE:** All projects made or updated in 2023 and after are only tested with Arduino Mega 2560, because there are no more units for tests available for me.

> **NOTE:** The compatibility with other boards are guaranteed from compatibility with others libraries dependencies and the Arduino's documentation.

## Arduino Libraries:

> **NOTE:** *THIS TABLE IS NOT UPDATED. SOME PROJECTS MAY NOT AVAILABLE OR THEIR VERSION MAY NOT BE CORRECT*

| Library Name | Description | Version | Boards Compatibility | Notes |
| ------------ | ----------- | ------- | -------------------- | ----- |
| Analog Common | Base library to control analogic devices on Arduino boards. | 1.0.3b | ALL BOARDS | This library only works with 10-bits analog reading data, leaving the value range from 0 to 255. 
| Analog Shield Buttons Lib | Library to control multiple buttons in one analogic pin, using different resistances to make changes on pin's reading. | 1.0.0 | ALL BOARDS | There is a definition that allow to work with 12-bits and 16-bits boards |
| Button Pullup Lib | Library to manage pullup buttons on Arduino boards | 1.0.1 | ALL BOARDS |
| Display Lib | Library to manage the LCD displays on Arduino boards | 0.0.1a | Arduino Uno, Arduino Mega 2560 |
| LED Lib | Library to manage LEDs on Arduino boards | 2.0.0 | ALL BOARDS |
| Relay Lib | Control the relay from an object and provide support to identify if is active or not and the relay type | 0.5.0b | ALL BOARDS |
| Thermo-Hydrometer | An class library that has the history of minimum, current and maximum values of air humidity and temperature (stored as Celsius or Fahrenheit, need be settled first) | 1.0.3 | ALL BOARDS | This library is inherits from WeatherDhtLib. |
| Weather Dht Lib | Easy access to DHT sensor's control | 1.1.5 | ALL BOARDS |

## TestSketch.ino:

The `TestSketch.ino` is an Arduino's project only for tests purposes and is frequently modified. The file located inside the repository's root is a template to make fast tests sketches.

## About the Visual Studio Code:

The Visual Studio Code is the main development software, used to create and tests the libraries. Consider to avoid or ignore the commits to local Visual Studio Code settings file, specially from `arduino.path` setting necessary to use to work with Arduino IDE resources.

## Additional Documentation:

An additional documentation is available [here](./Docs)

## License:

An copy of this license is available [here](./LICENSE.txt)

MIT License

Copyright (c) 2022-2024 Matheus Lopes Silvati

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.