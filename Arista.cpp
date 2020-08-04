//
// Created by mlora on 4/8/20.
//

#include "Arista.h"
using namespace std;

Arista::Arista(Vertice* destino, unsigned int peso) {
    if (destino != NULL) {
        this->destino = destino;
        this->peso = peso;
    }
}

Vertice* Arista::obtener_destino() {
    return this->destino;
}

unsigned int Arista::obtener_peso() {
    return this->peso;
}

void Arista :: cambiar_peso (int peso){
    this -> peso = peso;
}

Elemento* Arista::obtener_aeropuerto() {
    return this->aeropuerto;
}

Arista::~Arista() {
}