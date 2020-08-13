#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino, unsigned peso, unsigned tiempo) {
    if (destino != NULL) {
        this->destino = destino;
        this->peso = peso;
        this->tiempo = tiempo;
    }
}

Vertice* Arista::obtener_destino() {
    return this->destino;
}

unsigned Arista::obtener_peso() {
    return this->peso;
}

unsigned Arista::obtener_tiempo() {
    return this->tiempo;
}

void Arista :: cambiar_tiempo (unsigned tiempo) {
    this->tiempo = tiempo;
}

void Arista :: cambiar_peso(unsigned peso){
    this -> peso = peso;
}

Arista::~Arista() {
}
