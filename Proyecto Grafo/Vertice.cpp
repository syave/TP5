#include "Vertice.h"

using namespace std;

Vertice::Vertice() {
    this->elemento = "";
    this->adyacentes = NULL;
    this->indice = 0;
}

Vertice::Vertice(string elemento, unsigned int indice) {
    if (elemento != "" && indice >= 0) {
        this->elemento = elemento;
        this->adyacentes = new Lista<Arista*>();
        this->indice = indice;
    }
}

Lista<Arista*>* Vertice::obtener_adyacentes() {
    return this->adyacentes;
}

string Vertice::obtener_elemento() {
    return this->elemento;
}

unsigned int Vertice::obtener_indice() {
    return this->indice;
}

void Vertice::agregar_arista(Arista* nueva_arista) {
    if (nueva_arista != NULL)
        this->adyacentes->agregar(nueva_arista);
}

void Vertice::cambiar_elemento(string nuevo_elemento) {
    if (nuevo_elemento != "")
        this->elemento = nuevo_elemento;
}

void Vertice::decrecer_indice() {
    indice--;
}

Vertice::~Vertice() {
    this->adyacentes->iniciar_cursor();
    while (this->adyacentes->avanzar_cursor()) {
        delete this->adyacentes->obtener_cursor();
    }
    delete adyacentes;
}
