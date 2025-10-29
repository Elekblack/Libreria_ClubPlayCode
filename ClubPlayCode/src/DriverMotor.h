#ifndef DriverMotor_h
#define DriverMotor_h

#include <Arduino.h>

class DriverMotor {
public:
    // Constructor: recibe los pines del motor
    DriverMotor(uint8_t in1, uint8_t in2);

    // Inicializa los pines
    void iniciar();

    // Movimiento hacia adelante, con velocidad opcional (0-255)
    void avanzar(uint8_t velocidad = 255);

    // Movimiento hacia atrás, con velocidad opcional (0-255)
    void retroceder(uint8_t velocidad = 255);

    // Detiene el motor
    void detener();

private:
    uint8_t _in1, _in2;

    // Solo para ESP32: configuración de canales PWM
    #ifdef ESP32
    uint8_t _canal1;
    uint8_t _canal2;
    #endif
};

#endif
