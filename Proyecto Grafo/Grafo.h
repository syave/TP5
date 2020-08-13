#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "ColaPrioridad.h"
using namespace std;

class Grafo {

private:
    Lista<Vertice*>* vertices;
    unsigned tam;

public:
    // PRE:  ---
    // POST: grafo generado y vacio.
    Grafo();

    // POST: Devuelve el tamaño del grafo (cuantos vertices tiene)
    unsigned obtener_tam();

    // POST: Devuelve la lista de vertices del grafo.
    Lista<Vertice*>* obtener_vertices();


    void insertar_nodo(string elemento);

    // PRE:  Que el grafo exista y que el nodo no este previamente.
    // POST: El grafo queda modificado por el agregado del nuevo nodo.
    void insertar_nodo(string elemento, unsigned int indice);

    // PRE:  Que el grafo exista, que la arista no este previamente y que existan en el grafo los
    //       nodos origen y destino de la arista.
    // POST: El grafo queda modificado por el agregado de la nueva arista.
    void insertar_arista(string elemento_origen, string elemento_destino, float peso, float tiempo);

    // PRE:  Que el grafo exista, que la arista no este previamente y que existan en el grafo los
    //       nodos origen y destino de la arista que estan expresados por los parametros indice.
    // POST: El grafo queda modificado por el agregado de la nueva arista.
    void insertar_arista(unsigned int indice_vertice_origen, unsigned int indice_vertice_destino, unsigned peso, unsigned tiempo);

    // PRE:  Que el grafo exista y que el nodo a eliminar este en el y no tenga aristas incidentes en el.
    // POST: El grafo queda modificado por la eliminacion del nodo.
    void eliminar_nodo(Vertice* eliminar);

    // PRE:  Que el grafo exista y la arista esten el.
    // POST: El grafo queda modificado por la eliminacion de la arista.
    void Eliminar_arista(Vertice* origen, Vertice* destino);

    // PRE:  Que el grafo exista.
    // POST: Indica si hay una arista entre los vertices origen y destino.
    bool existe_arista(Vertice* origen, Vertice* destino);

    // PRE:  Que el grafo exista.
    // POST: Devuelve el nodo con el nombre que se paso por referencia. Si no existe devuelve NULL.
    Vertice* existe_nodo(string elemento);

    // PRE:  Los elementos deben existir.
    // POST: Indica si los elementos a comparar son iguales por tipo y por ubicacion.
    bool elementos_son_iguales(string primer_elemento, string segundo_elemento);

    // POST: Devuelve, en caso de existir, el vertice cuyo indice es el pasado como parametro.
    Vertice* obtener_vertice_por_indice(unsigned int indice);


    // POST: Devuelve, en caso de existir, el vertice cuyo indice es el pasado como parametro.
    Vertice* obtener_vertice_por_elemento(string elemento);


    // PRE:  Que el grafo exista.
    // POST: Libera los recursos utilizados por el grafo.
    ~Grafo();

    // PRE:
    // POST:
    void obtener_camino_minimo(Vertice *origen, Vertice *destino, unsigned opcion);

    // PRE:
    // POST:
    int* inicializar_vector_rutas();

    // PRE:
    // POST:
    unsigned* inicializar_vector(Vertice* origen, unsigned opcion);

    // PRE:
    // POST:
    ColaPrioridad<Vertice*>* inicializar_cola(Vertice* origen, unsigned* costos);

    // Devuelve la lista de vertices que componen el minimo camino seleccionado para recorrer (lo usa el Dijkstra).
    // PRE:
    // POST:
    void construir_camino(int padre[], int indice, Lista<Vertice*>* &vertices);

    // Funcion para imprimir la ruta mas corta desde un origen hasta j usando el vector 'padre'.
    // PRE:
    // POST:
    void imprimir_camino(int padre[], int indice);

    // Una funcion de utilidad para imprimir el vector construido de distancias.
    // PRE:
    // POST:
    void imprimir_todos_los_caminos(unsigned* dist, int padre[]);

    void imprimir_camino_total(unsigned* dist, int indice, int padre[], unsigned origen);

};
#endif // GRAFO_H_
