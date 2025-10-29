#include "SensorUltrasonico.h"

SensorUltrasonico::SensorUltrasonico(uint8_t trig, uint8_t echo) {
    _trig = trig;
    _echo = echo;
}

void SensorUltrasonico::iniciar() {
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
}

float SensorUltrasonico::leerDistancia() {
    // Enviar pulso de 10 µs al TRIG
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    // Medir duración del eco con timeout (30 ms)
    long duracion = pulseIn(_echo, HIGH, 30000UL);

    // Si no hay eco, devolver -1
    if (duracion == 0) return -1;

    // Calcular distancia en cm
    float distancia = duracion * 0.0343 / 2;

    // Limitar rango útil (2 cm a 400 cm)
    if (distancia < 2 || distancia > 400) return -1;

    return distancia;
}
