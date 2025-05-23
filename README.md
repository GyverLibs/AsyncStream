[![latest](https://img.shields.io/github/v/release/GyverLibs/AsyncStream.svg?color=brightgreen)](https://github.com/GyverLibs/AsyncStream/releases/latest/download/AsyncStream.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/AsyncStream.svg)](https://registry.platformio.org/libraries/gyverlibs/AsyncStream)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/AsyncStream?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

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
### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи
- Через менеджер библиотек IDE: найти библиотеку как при установке и нажать "Обновить"
- Вручную: **удалить папку со старой версией**, а затем положить на её место новую. "Замену" делать нельзя: иногда в новых версиях удаляются файлы, которые останутся при замене и могут привести к ошибкам!


<a id="init"></a>

## Инициализация
```cpp
// <размер буфера>
// Stream обработчик (Serial, SoftwareSerial итд)
// терминатор (символ конца приёма) - по умолчанию ';' (вырезается из буфера!)
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
uint16_t length();              // количество данных в буфере

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
- v1.1 - исправлен баг

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!


При сообщении о багах или некорректной работе библиотеки нужно обязательно указывать:
- Версия библиотеки
- Какой используется МК
- Версия SDK (для ESP)
- Версия Arduino IDE
- Корректно ли работают ли встроенные примеры, в которых используются функции и конструкции, приводящие к багу в вашем коде
- Какой код загружался, какая работа от него ожидалась и как он работает в реальности
- В идеале приложить минимальный код, в котором наблюдается баг. Не полотно из тысячи строк, а минимальный код
