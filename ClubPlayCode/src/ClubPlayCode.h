#ifndef ClubPlayCode_h
#define ClubPlayCode_h

#include <Arduino.h>
#include "SensorUltrasonico.h"
#include "DriverMotor.h"

class ClubPlayCode {
public:
    ClubPlayCode(uint8_t trig, uint8_t echo,
                uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    void iniciar();
    void avanzar(uint8_t velocidad = 255);
    void retroceder(uint8_t velocidad = 255);
    void girarDerecha(uint8_t velocidad = 255);
    void girarIzquierda(uint8_t velocidad = 255);
    void detener();
    float leerDistancia();
private:
    SensorUltrasonico _sensor;
    DriverMotor _motorIzq;
    DriverMotor _motorDer;
};

#endif
