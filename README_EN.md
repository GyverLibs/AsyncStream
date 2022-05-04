This is an automatic translation, may be incorrect in some places. See sources and examples!

# AsyncStream
Library for asynchronous reading of Stream objects (Serial, etc.)
- Non-blocking read into own buffer
- Specifying a terminator characterCranberry
### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found by the name **AsyncStream** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download library](https://github.com/GyverLibs/AsyncStream/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)- Extract and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
// <buffer size>
// Stream handler (Serial, SoftwareSerial etc)// terminator (terminator) - default ';'
// timeout in ms - default 50
AsyncStream<100> serial(&Serial);
AsyncStream<100> serial(&Serial, '\n');
AsyncStream<100> serial(&Serial, '\n', 20);
```

<a id="usage"></a>
## Usage
```cppvoid setTimeout(uint16_t tout); // set timeout
void setEOL(charter); // set end character
bool available(); // data received
charbuf; // buffer access
```

<a id="example"></a>
## Example
See **examples** for other examples!
```cpp#include <AsyncStream.h>
AsyncStream<100> serial(&Serial, '\n');

void setup() {
  Serial.begin(9600);
  // serial setTimeout(100); // set another timeout
  //serial.setEOL(';'); // set another terminator (EOL)
}

// test string (send to serial)// 1234,3.14,hello,4567,lolkek,qwerty
void loop() {
  if (serial.available()) { // if data is received
    Serial.println(serial.buf); // output them (as char*)
  }
}
```

<a id="versions"></a>
## Versions- v1.0

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!