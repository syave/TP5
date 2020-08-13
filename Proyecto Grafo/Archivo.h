#ifndef GRAFOS_ARCHIVO_H
#define GRAFOS_ARCHIVO_H

#include "Vuelos.h"
#include "Aeropuerto.h"
#include "Grafo.h"
#include <fstream>
#include <iostream>

const string NOMBRE_ARCHIVO = "vuelos.txt";

class Archivo {
private:
    Vuelos* puntero;
    Aeropuerto* origen;
    Aeropuerto* destino;
    ifstream archivo;
public:
    Archivo();
    ~Archivo();

    void cargar_archivo(Grafo &grafo);
};

#endif //GRAFOS_ARCHIVO_H
