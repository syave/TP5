#ifndef GRAFOS_VUELOS_H
#define GRAFOS_VUELOS_H

#include "Aeropuerto.h"

class Vuelos {
private:
    Aeropuerto* origen;
    Aeropuerto* destino;
    unsigned horas_viaje;
    unsigned valor_boleto;
public:
    Vuelos();
    ~Vuelos();

    void set_horas_viaje(float horas_viaje);
    unsigned get_horas_viaje();

    void set_valor_boleto(unsigned valor_boleto);
    unsigned get_valor_boleto();

    Aeropuerto* set_aeropuerto_origen(Aeropuerto* origen);
    Aeropuerto* get_aeropuerto_origen();

    Aeropuerto* set_aeropuerto_destino(Aeropuerto* destino);
    Aeropuerto* get_aeropuerto_destino();


};


#endif //GRAFOS_VUELOS_H
