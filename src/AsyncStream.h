/*
    Библиотека для асинхронного чтения объектов Stream (Serial итд)
    Документация:
    GitHub: https://github.com/GyverLibs/AsyncStream
    Возможности:
    - Неблокирующее чтение в свой буфер
    - Указание символа терминатора

    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.0 - релиз
    v1.1 - исправлен баг
*/

#pragma once
#include <Arduino.h>

template <uint16_t SIZE>
class AsyncStream {
   public:
    static_assert(SIZE > 0, "AsyncStream buffer size must be greater than zero");

    AsyncStream(Stream* port, char ter = ';', uint16_t tout = 50) : _port(port), _ter(ter), _tout(tout) {}
    AsyncStream(Stream& port, char ter = ';', uint16_t tout = 50) : AsyncStream(&port, ter, tout) {}

    // установить таймаут
    void setTimeout(uint16_t tout) {
        _tout = tout;
    }

    // установить символ конца
    void setEOL(char ter) {
        _ter = ter;
    }

    // данные приняты
    bool available() {
        if (!_port) return false;

        while (_port->available()) {
            int data = _port->read();
            if (data < 0) break;

            if (!_parseF) {
                _parseF = true;
                _count = 0;
                _overflow = false;
                _tmr = millis();
            }

            char ch = data;
            if (ch == _ter) {
                return _finish();
            } else if (_count < SIZE - 1) {
                buf[_count++] = ch;
            } else {
                _overflow = true;
            }
            _tmr = millis();
        }

        if (_parseF && millis() - _tmr >= _tout) {
            return _finish();
        }
        return false;
    }

    // количество данных в буфере
    uint16_t length() const {
        return _count;
    }

    // доступ к буферу
    char buf[SIZE];

   private:
    bool _finish() {
        _parseF = false;
        buf[_count] = '\0';
        return !_overflow;
    }

    Stream* _port;
    char _ter;
    uint16_t _tout, _count = 0;
    uint32_t _tmr = 0;
    bool _parseF = false;
    bool _overflow = false;
};
