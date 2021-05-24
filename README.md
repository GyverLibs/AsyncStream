![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
# AsyncStream
Библиотека для асинхронного чтения объектов Stream (Serial итд)
- Неблокирующее чтение в свой буфер
- Указание символа терминатора

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **AsyncStream** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/AsyncStream/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
// <размер буфера>
// Stream обработчик (Serial, SoftwareSerial итд)
// терминатор (символ конца приёма) - по умолчанию ';'
// таймаут в мс - по умолчанию 50
AsyncStream<100> serial(&Serial);
AsyncStream<100> serial(&Serial, '\n');
AsyncStream<100> serial(&Serial, '\n', 20);
```

<a id="usage"></a>
## Использование
```cpp
void setTimeout(uint16_t tout); // установить таймаут
void setEOL(char ter);          // установить символ конца
bool available();               // данные приняты
char buf;                       // доступ к буферу
```

<a id="example"></a>
## Пример
Остальные примеры смотри в **examples**!
```cpp
#include <AsyncStream.h>
AsyncStream<100> serial(&Serial, '\n');

void setup() {
  Serial.begin(9600);
  // serial.setTimeout(100);	// установить другой таймаут
  // serial.setEOL(';');		// установить другой терминатор (EOL)
}

// строка для теста (отправь в сериал)
// 1234,3.14,hello,4567,lolkek,qwerty
void loop() {
  if (serial.available()) {     // если данные получены
    Serial.println(serial.buf); // выводим их (как char*)    
  }
}
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!