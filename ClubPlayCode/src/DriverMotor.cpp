#include "DriverMotor.h"

DriverMotor::DriverMotor(uint8_t in1, uint8_t in2) {
    _in1 = in1;
    _in2 = in2;

    #ifdef ESP32
    // Usamos los mismos números de pin como canal (simple y funcional)
    _canal1 = in1;
    _canal2 = in2;
    #endif
}

void DriverMotor::iniciar() {
    #ifdef ESP32
    // Configura PWM en ambos pines
    ledcSetup(_canal1, 1000, 8); // 1 kHz, 8 bits
    ledcSetup(_canal2, 1000, 8);
    ledcAttachPin(_in1, _canal1);
    ledcAttachPin(_in2, _canal2);
    #else
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    #endif
    detener();
}

void DriverMotor::avanzar(uint8_t velocidad) {
    #ifdef ESP32
    ledcWrite(_canal1, velocidad); // PWM en IN1
    ledcWrite(_canal2, 0);         // LOW en IN2
    #else
    analogWrite(_in1, velocidad);  // PWM en IN1
    digitalWrite(_in2, LOW);
    #endif
}

void DriverMotor::retroceder(uint8_t velocidad) {
    #ifdef ESP32
    ledcWrite(_canal1, 0);
    ledcWrite(_canal2, velocidad);
    #else
    digitalWrite(_in1, LOW);
    analogWrite(_in2, velocidad);
    #endif
}

void DriverMotor::detener() {
    #ifdef ESP32
    ledcWrite(_canal1, 0);
    ledcWrite(_canal2, 0);
    #else
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    #endif
}
