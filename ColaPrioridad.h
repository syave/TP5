    //
// Created by mlora on 6/8/20.
//

#ifndef TP5_COLAPRIORIDAD_H
#define TP5_COLAPRIORIDAD_H
#include <string>
#include "nodo.h"

template<class T> class ColaPrioridad {

    public:
        // PRE :
        // POST:
        ColaPrioridad();

        // PRE :
        // POST:
        void actualizar_valor(T vertice, unsigned int prioridad);

        // PRE :
        // POST:
        bool esta_vacia();

        // PRE :
        // POST:
        void acolar(T elemento, unsigned int prioridad);

        // PRE :
        // POST:
        T desacolar();

        // PRE :
        // POST:
        T obtener_frente();

        // PRE :
        // POST:
        void ordenar();

        // PRE :
        // POST:
        ~ColaPrioridad();

    private:
        Nodo<T>* frente;
        Nodo<T>* fondo;
};


template<class T>
ColaPrioridad<T>::ColaPrioridad() {
    this->frente = NULL;
    this->fondo = NULL;
}


template<class T>
bool ColaPrioridad<T>::esta_vacia() {
    return (this->frente == NULL);
}

template<class T>
void ColaPrioridad<T>::acolar(T elemento, unsigned int prioridad) {
    if (prioridad >= 0) {
        Nodo<T>* nuevo_fondo = new Nodo<T>(elemento);
        nuevo_fondo->cambiar_prioridad(prioridad);
        if (this->esta_vacia()) {
            this->frente = nuevo_fondo;
            this->fondo = nuevo_fondo;
        } else if (this->frente->obtener_prioridad() > prioridad) {
            Nodo<T>* nodo_siguiente = this->frente;
            this->frente = nuevo_fondo;
            nuevo_fondo->cambiar_siguiente(nodo_siguiente);
        } else {
            Nodo<T>* Cambiar = this->frente;
            while (Cambiar->obtener_siguiente() != NULL && Cambiar->obtener_siguiente()->obtener_prioridad() < prioridad) {
                Cambiar = Cambiar->obtener_siguiente();
            }
            Nodo<T>* siguiente = Cambiar->obtener_siguiente();
            Cambiar->cambiar_siguiente(nuevo_fondo);
            nuevo_fondo->cambiar_siguiente(siguiente);
            if (siguiente == NULL) {
                this->fondo = nuevo_fondo;
            }
        }
    }
}


template<class T>
void ColaPrioridad<T>::actualizar_valor(T vertice, unsigned int valor) {
    Nodo<T>* nodo_buscado = this->frente;
    bool encontrado = (this->frente->obtener_dato() == vertice);
    while (nodo_buscado != NULL && !encontrado) {
        nodo_buscado = nodo_buscado->obtener_siguiente();
        encontrado = (nodo_buscado->obtener_dato() == vertice);
    }
    nodo_buscado->cambiar_prioridad(valor);
    this->ordenar();
}


template<class T>
void ColaPrioridad <T> :: ordenar(){
    Nodo<T>* anterior = this->frente;
    unsigned int prioridad_anterior;
    T dato_anterior;

    while (anterior->obtener_siguiente() != NULL) {
        Nodo<T>* siguiente = anterior->obtener_siguiente();
        while (siguiente != NULL) {
            if (anterior->obtener_prioridad() > siguiente->obtener_prioridad()) {
                prioridad_anterior = anterior->obtener_prioridad();
                dato_anterior = anterior->obtener_dato();

                anterior->cambiar_prioridad(siguiente->obtener_prioridad());
                anterior->cambiar_dato(siguiente->obtener_dato());

                siguiente->cambiar_prioridad(prioridad_anterior);
                siguiente->cambiar_dato(dato_anterior);
            }
            siguiente = siguiente->obtener_siguiente();
        }
        anterior = anterior->obtener_siguiente();
    }
}

template<class T>
T ColaPrioridad<T>::desacolar() {
    if (this->esta_vacia()) {
        throw std::string("Cola Vacia : No se puede desacolar");
    }
    Nodo<T>* frente_anterior = this->frente;
    this->frente = frente_anterior->obtener_siguiente();
    if (this->frente == NULL) {
        this->fondo = NULL;
    }
    T elemento = frente_anterior->obtener_dato();
    delete frente_anterior;
    return elemento;
}

template<class T>
T ColaPrioridad<T>::obtener_frente() {
    if (this->esta_vacia()) {
        throw std::string(
                "Cola Vacia: No se puede obtener el frente");
    }
    T elemento = this->frente->obtener_dato();
    return elemento;
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
    while (!this->esta_vacia()) {
        this->desacolar();
    }
}

#endif //TP5_COLAPRIORIDAD_H
