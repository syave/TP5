#include "Archivo.h"

Archivo::Archivo() {
    archivo.open(NOMBRE_ARCHIVO);
    puntero = 0;
    origen = 0;
    destino = 0;
}

Archivo::~Archivo() {

}

void Archivo::cargar_archivo(Grafo &grafo) {
    double horasViaje;
    unsigned valorBoleto;
    string codigoOrigen,codigoDestino;

    if(!archivo.fail()) {
        while (archivo >> codigoOrigen) {
            puntero = new Vuelos();
            origen = new Aeropuerto();
            destino = new Aeropuerto();

            puntero->set_aeropuerto_origen(origen);
            origen->set_codigo(codigoOrigen);

            archivo >> codigoDestino;
            puntero->set_aeropuerto_destino(destino);
            destino->set_codigo(codigoDestino);

            archivo >> valorBoleto;
            puntero->set_valor_boleto(valorBoleto);

            archivo >> horasViaje;
            unsigned minViaje = (int)((horasViaje*10))*6;
            puntero->set_horas_viaje(horasViaje);

            grafo.insertar_nodo(origen->get_codigo());
            grafo.insertar_nodo(destino->get_codigo());
            grafo.insertar_arista(origen->get_codigo(),destino->get_codigo(),valorBoleto, minViaje);
            delete puntero,origen,destino;

        }
    }else {
        cout << "No hay archivo" <<endl;
    }
    puntero = 0,origen = 0,destino = 0;
    //delete puntero,origen,destino;
    archivo.close();
}
