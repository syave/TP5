//
// Created by mlora on 4/8/20.
//

#ifndef TP5_VERTICE_H
#define TP5_VERTICE_H



#include <iostream>
#include <string>
#include "elemento.h"
#include "Arista.h"
#include "lista.h"

class Vertice {

    public:

        // PRE:  --
        // POST: --
        Vertice();

        // PRE:  --
        // POST: --
        Vertice(Elemento* elemento, unsigned int indice);

        // PRE:  --
        // POST: --
        Elemento* obtener_elemento();

        // PRE:  --
        // POST: --
        Lista<Arista*>* obtener_adyacentes();

        // PRE:  --
        // POST: --
        unsigned int obtener_indice();

        // PRE:  --
        // POST: --
        void agregar_arista(Arista* nueva_arista);

        // PRE:  --
        // POST: --
        void cambiar_elemento(Elemento* nuevo_elemento);


        // PRE:  --
        // POST: --
        void decrecer_indice();

        // PRE:  --
        // POST: --
        ~Vertice();


    private:
        Elemento* elemento;
        Lista<Arista*>* adyacentes;
        unsigned int indice;
};




#endif //TP5_VERTICE_H
