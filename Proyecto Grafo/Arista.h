#ifndef ARISTA_H
#define ARISTA_H_
#include <iostream>
using namespace std;
class Vertice;

class Arista {
private:
    Vertice* destino;
    string elemento;
    unsigned peso;
    unsigned tiempo;

public:

    // POST: Arista con un destino, un peso y tiempo fijados.
    Arista(Vertice* destino, unsigned peso, unsigned tiempo);

    // POST: Devuelve el destino asociado a la arista.
    Vertice* obtener_destino();

    // POST: devuelve el valor peso de la arista.
    unsigned obtener_peso();

    // POST: devuelve el valor tiempo (minutos) de la arista.
    unsigned obtener_tiempo();



    void cambiar_tiempo(unsigned tiempo);

    void cambiar_peso(unsigned peso);



    // POST: ---
    ~Arista();
};

#endif // ARISTA_H_
