//
// Created by mlora on 6/8/20.
//

#ifndef TP5_LISTA_H
#define TP5_LISTA_H


#include "nodo.h"

template<class T> class Lista {

    public:
        // PRE :
        // POST:
        Lista();

        // PRE :
        // POST:
        Lista(Lista<T>& otraLista);

        // PRE :
        // POST:
        bool esta_vacia();

        // PRE :
        // POST:
        unsigned int contar_elementos();

        // PRE :
        // POST:
        void agregar(T elemento);

        // PRE :
        // POST:
        void agregar(T elemento, unsigned int posicion);

        // PRE :
        // POST:
        void agregar(Lista<T> &otra_lista);

        // PRE :
        // POST:
        T obtener(unsigned int posicion);

        // PRE :
        // POST:
        void asignar(T elemento, unsigned int posicion);

        // PRE :
        // POST:
        void remover(unsigned int posicion);

        // PRE :
        // POST:
        void remover(T elemento);

        // PRE :
        // POST:
        void iniciar_cursor();

        // PRE :
        // POST:
        bool avanzar_cursor();

        // PRE :
        // POST:
        T obtener_cursor();

        // PRE :
        // POST:
        ~Lista();
    private:
        Nodo<T>* primero;
        unsigned int tamanio;
        Nodo<T>* cursor;

        // PRE :
        // POST:
        Nodo<T>* obtener_nodo(unsigned int posicion);
};

template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otra_lista) {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    // Copia los elementos de otraLista
    this->agregar(otra_lista);
}

template<class T> bool Lista<T>::esta_vacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contar_elementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->cambiar_siguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = this->obtener_nodo(posicion - 1);
            nuevo->cambiar_siguiente(anterior->obtener_siguiente());
            anterior->cambiar_siguiente(nuevo);
        }

        this->tamanio++;

        // Cualquier recorrido actual queda invalidado
        this->iniciar_cursor();
    }

}

template<class T> void Lista<T>::agregar(Lista<T> &otra_lista) {

    otra_lista.iniciar_cursor();
    while (otra_lista.avanzar_cursor()) {
        this->agregar(otra_lista.obtener_cursor());
    }
}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtener_nodo(posicion)->obtener_dato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtener_nodo(posicion)->cambiar_dato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtener_siguiente();

        } else {

            Nodo<T>* anterior = this->obtener_nodo(posicion - 1);
            removido = anterior->obtener_siguiente();
            anterior->cambiar_siguiente(removido->obtener_siguiente());
        }

        delete removido;
        this->tamanio--;

        // Cualquier recorrido actual queda invalidado.
        this->iniciar_cursor();
    }
}

template<class T> void Lista<T>::remover(T elemento) {
    int posicion = 1;
    this->iniciar_cursor();
    while (this->avanzar_cursor()) {
        T elemento_actual = this->obtener_cursor();
        if (elemento_actual == elemento) {
            Nodo<T>* removido;
            if (posicion == 1) {
                removido = this->primero;
                this->primero = removido->obtener_siguiente();
            } else {
                Nodo<T>* anterior = this->obtener_nodo(posicion - 1);
                removido = anterior->obtener_siguiente();
                anterior->cambiar_siguiente(removido->obtener_siguiente());
            }
            delete removido;
            this->tamanio--;
            // Cualquier recorrido actual queda invalidado.
            this->iniciar_cursor();
        }
        posicion++;
    }
}

template<class T> void Lista<T>::iniciar_cursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzar_cursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtener_siguiente();
    }

    // Pudo avanzar si el cursor ahora apunta a un nodo.
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtener_cursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtener_dato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {

    while (this->primero != NULL) {

        Nodo<T>* a_borrar = this->primero;
        this->primero = this->primero->obtener_siguiente();

        delete a_borrar;
    }
}

template<class T> Nodo<T>* Lista<T>::obtener_nodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtener_siguiente();
    }

    return actual;
}


#endif //TP5_LISTA_H
