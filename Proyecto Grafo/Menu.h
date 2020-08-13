#ifndef GRAFOS_MENU_H
#define GRAFOS_MENU_H

#include "Archivo.h"
#include "Grafo.h"

class Menu {
private:
    Archivo archivo;
    Grafo grafo;
    unsigned entrada;

public:
    Menu();
    ~Menu();

    void mostrar_menu();
    void limpiar_pantalla();

    void cargar_vuelos();
    string consultar_codigo_iata_origen();
    string consultar_codigo_iata_destino();
    void vuelo_mas_economico();
    void vuelo_menor_tiempo();
private:

    void mensaje();
    void menu_vuelos();
    void validar_entrada(unsigned &, unsigned);
    void verificar(unsigned &);
    void imprimir_aeropuertos_disponibles();

};


#endif //GRAFOS_MENU_H
