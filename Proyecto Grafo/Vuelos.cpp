#include "Vuelos.h"

Vuelos::Vuelos() {
    origen = 0;
    destino = 0;
    horas_viaje = 0;
    valor_boleto = 0;
}

void Vuelos::set_valor_boleto(unsigned int valor_boleto) {
    this->valor_boleto = valor_boleto;
}

void Vuelos::set_horas_viaje(float horas_viaje) {
    this->horas_viaje = horas_viaje;
}

unsigned Vuelos::get_horas_viaje() {
    return this->horas_viaje;
}

unsigned Vuelos::get_valor_boleto() {
    return this->valor_boleto;
}

Aeropuerto* Vuelos::set_aeropuerto_origen(Aeropuerto *origen) {
    this-> origen = origen;
}

Aeropuerto* Vuelos::get_aeropuerto_origen() {
    return this->origen;
}

Aeropuerto* Vuelos::set_aeropuerto_destino(Aeropuerto *destino) {
    this-> destino =  destino;
}

Aeropuerto* Vuelos::get_aeropuerto_destino() {
    return this->destino;
}

Vuelos::~Vuelos() {
    delete this->origen;
    delete this->destino;
}


