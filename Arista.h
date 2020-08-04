//
// Created by mlora on 4/8/20.
//
#include "elemento.h"
#include <iostream>

#ifndef TP5_ARISTA_H
#define TP5_ARISTA_H



class Vertice;

class Arista {
    public:
        // PRE :
        // POST:
        Arista(Vertice* destino, unsigned int peso);

        // PRE :
        // POST:
        Vertice* obtener_destino();

        // PRE :
        // POST:
        unsigned int obtener_peso();

        // PRE :
        // POST:
        void cambiar_peso(int peso);

        // PRE :
        // POST:
        Elemento* obtener_aeropuerto();

        // PRE :
        // POST:
        ~Arista();

    private:
        Vertice* destino;
        Elemento* aeropuerto;
        unsigned int peso;

};


#endif //TP5_ARISTA_H
