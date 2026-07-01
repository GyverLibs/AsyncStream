This is an automatic translation and may be incorrect in some places. See the source README and examples for authoritative information.

[![latest](https://img.shields.io/github/v/release/GyverLibs/AsyncStream.svg?color=brightgreen)](https://github.com/GyverLibs/AsyncStream/releases/latest/download/AsyncStream.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/AsyncStream.svg)](https://registry.platformio.org/libraries/gyverlibs/AsyncStream)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/AsyncStream?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# AsyncStream
Library for asynchronous reading of Stream objects (Serial etc.)
- Non-blocking reading in your buffer
- Indication of the terminator symbol

### Compatibility
Compatible with all Arduino platforms (Arduino features are used)

## Contents
- [Installation](#install)
- [Initialization](#init)
- [Use of use](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found under the name **AsyncStream** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download the library](https://github.com/GyverLibs/AsyncStream/archive/refs/heads/main.zip).zip archive for manual installation:
    - Unpack and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unpack and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/ *
    - (Arduino IDE) Automatic installation from .zip: *Sketch/Connect library/Add .ZIP library...* and specify downloaded archive
- Read more detailed instructions for installing libraries[here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: new versions fix errors and bugs, as well as optimize and add new features.
- Through the library manager IDE: find the library as when installing and click "Update"
- Manually: **Delete the folder with the old version** and then put the new one in its place. “Replacement” can not be done: sometimes new versions delete files that will remain when replaced and can lead to errors!

<a id="init"></a>

## Initialization
```cpp
// <buffer size >>
// Stream Processor (Serial, SoftwareSerial, etc.)
// Terminator (symbol of the end of reception) - by default ";" (cut out of the buffer!)
// timeout in ms - default 50
AsyncStream<100> serial(Serial);
AsyncStream<100> serial(Serial, '\n');
AsyncStream<100> serial(Serial, '\n', 20);
```

The buffer size must be greater than zero and includes the terminating `\0`, so
the maximum message length is `SIZE - 1`. An overflowing frame is discarded
entirely. When the timeout expires, the accumulated partial message is returned
as complete.

<a id="usage"></a>

## Use of use
```cpp
void setTimeout(uint16_t tout); // time-out
void setEOL(char ter);          // signify
bool available();               // received
uint16_t length();              // buffer

char buf[SIZE];                 // buffer access
```

One `available()` call reads all currently available bytes through the end of
the first message. A following message is handled by the next call.

<a id="example"></a>

## Example
For more examples see **examples**!
```cpp
#include <AsyncStream.h>
AsyncStream<100> serial(Serial, '\n');

void setup() {
  Serial.begin(9600);
  // serial.setTimeout(100) // set another timeout
  // serial.setEOL(';'); Install another terminator (EOL)
}

// Test line (send to the series)
// 1234,3.14,hello,4567,lolkek,qwerty
void loop() {
  if (serial.available()) {     // data obtained
    Serial.println(serial.buf); // We take them out (like char*)
  }
}
```

<a id="versions"></a>
## Versions
- v1.0
- v1.1 - bug corrected

<a id="feedback"></a>
## Bugs and feedback
If you find bugs, create **Issue**, or better write to the mail immediately.[alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
The library is open for revision and your **Pull Requests*!

When reporting bugs or incorrect work of the library, it is necessary to specify:
- Library version
- What is used by the IC
- SDK version (for ESP)
- Arduino IDE version
- Are embedded examples that use features and designs that cause bugs in your code working correctly?
- What code was downloaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed. Not a canvas of a thousand lines, but a minimum code.
