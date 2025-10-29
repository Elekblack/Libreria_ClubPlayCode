#ifndef SensorUltrasonico_h
#define SensorUltrasonico_h

#include <Arduino.h>

class SensorUltrasonico {
public:
    SensorUltrasonico(uint8_t trig, uint8_t echo);
    void iniciar();
    float leerDistancia();
private:
    uint8_t _trig, _echo;
};

#endif
