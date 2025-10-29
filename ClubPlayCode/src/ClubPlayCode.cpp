#include "ClubPlayCode.h"

ClubPlayCode::ClubPlayCode(uint8_t trig, uint8_t echo,
                           uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4)
: _sensor(trig, echo), _motorIzq(in1, in2), _motorDer(in3, in4) {}

void ClubPlayCode::iniciar() {
    _sensor.iniciar();
    _motorIzq.iniciar();
    _motorDer.iniciar();
}

void ClubPlayCode::avanzar(uint8_t velocidad) {
    _motorIzq.avanzar(velocidad);
    _motorDer.avanzar(velocidad);
}

void ClubPlayCode::retroceder(uint8_t velocidad) {
    _motorIzq.retroceder(velocidad);
    _motorDer.retroceder(velocidad);
}

void ClubPlayCode::girarDerecha(uint8_t velocidad) {
    _motorIzq.avanzar(velocidad);
    _motorDer.retroceder(velocidad);
}

void ClubPlayCode::girarIzquierda(uint8_t velocidad) {
    _motorIzq.retroceder(velocidad);
    _motorDer.avanzar(velocidad);
}

void ClubPlayCode::detener() {
    _motorIzq.detener();
    _motorDer.detener();
}

float ClubPlayCode::leerDistancia() {
    return _sensor.leerDistancia();
}
