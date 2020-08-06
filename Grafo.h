//
// Created by mlora on 6/8/20.
//

#ifndef TP5_GRAFO_H
#define TP5_GRAFO_H



#include "Grafo.h"
#include <iostream>
#include <string>
#include "lista.h"
#include "Vertice.h"
#include "ColaPrioridad.h"


class Grafo {
    public:
        // PRE :
        // POST:
        Grafo();

        // PRE :
        // POST:
        unsigned int obtener_tam();

        // PRE :
        // POST:
        Lista<Vertice*>* obtener_vertices();

        // PRE :
        // POST:
        void insertar_nodo(Elemento* elemento, unsigned int indice);

        // PRE :
        // POST:
        void insertar_arista(Elemento* elemento_origen, Elemento* elemento_destino, unsigned int peso);

        // PRE :
        // POST:
        void insertar_arista(unsigned int indice_vertice_origen, unsigned int indice_vertice_destino, unsigned int peso);

        // PRE :
        // POST:
        void eliminar_nodo(Vertice* eliminar);

        // PRE :
        // POST:
        void Eliminar_arista(Vertice* origen, Vertice* destino);

        // PRE :
        // POST:
        bool existe_arista(Vertice* origen, Vertice* destino);

        // PRE :
        // POST:
        Vertice* existe_nodo(Elemento* elemento);

        // PRE :
        // POST:
        bool elementos_son_iguales(Elemento* primer_elemento, Elemento* segundo_elemento);

        // PRE :
        // POST:
        Vertice* obtener_vertice_por_indice(unsigned int indice);

        // PRE :
        // POST:
        ~Grafo();

        // PRE:
        // POST:
        Lista<Vertice*>* obtener_camino_minimo(Vertice* origen, Vertice* destino);

        // PRE:
        // POST:
        int* inicializar_vector_rutas();

        // PRE:
        // POST:
        unsigned int* inicializar_vector(Vertice* origen);

        // PRE:
        // POST:
        ColaPrioridad<Vertice*>* inicializar_cola(Vertice* origen, unsigned int* costos);

        // PRE :
        // POST:
        void construir_path(int parent[], int j, Lista<Vertice*>* &vertices);

        // PRE :
        // POST:
        void imprimir_path(int parent[], int j);

        // PRE :
        // POST:
        void imprimir_solucion(unsigned int* dist, int n, int parent[]);

    private:
        Lista<Vertice*>* vertices;
        unsigned int tam;
};


#endif //TP5_GRAFO_H
