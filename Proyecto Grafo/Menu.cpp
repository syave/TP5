#include "Menu.h"
const int ENCONTRADO = 1;
const int NO_ENCONTRADO = 0;

Menu::Menu() {
    entrada = 0;
}

Menu::~Menu() {
}

string Menu::consultar_codigo_iata_origen() {
    string codigoOrigen;
    cout << "Ingrese el codigo IATA del aeropuerto de origen: ";
    cin >> codigoOrigen;
    return codigoOrigen;
}

string Menu::consultar_codigo_iata_destino() {
    string codigoDestino;
    cout << "Ingrese el codigo IATA del aeropuerto del destino: ";
    cin >> codigoDestino;
    return codigoDestino;
}

void Menu::cargar_vuelos() {
    archivo.cargar_archivo(grafo);
}

void Menu::limpiar_pantalla() {

    #ifdef linux
        system("clear");
    #else
        system ("cls");
    #endif
}
void Menu::menu_vuelos() {
    cout << "--------------------------------------" << endl;
    cout << "VUELOS" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Por favor introduzca una opcion: " << endl;
    cout <<     " -1) Vuelo mas economico.\n"
                " -2) Vuelo de menor tiempo.\n"
                " -3) Salir.\n";
    cout << "--------------------------------------" << endl;
    cout << "Entrada: ";
}

void Menu::validar_entrada(unsigned &entrada, unsigned corte) {
    while((entrada > corte || entrada <= 0)){
        verificar(entrada);
    }
}

void Menu::verificar(unsigned & entrada) {
    mensaje();
    cout << "Entrada: ";
    cin.clear();
    cin.ignore(50,'\n');
    cin >> entrada;
}

void Menu::mensaje() {
    cout << "Entrada no valida.Por favor Intente de nuevo.\n";
}

void Menu::mostrar_menu() {
    cargar_vuelos();
    while (entrada != 3) {
        menu_vuelos();
        cin >> entrada;
        validar_entrada(entrada, 3);
        switch (entrada) {
            case 1:
                vuelo_mas_economico();
                break;
            case 2:
                vuelo_menor_tiempo();
                break;
            case 3: //salir
                limpiar_pantalla();
        }
    }
}

void Menu::vuelo_mas_economico() {
    unsigned opcion = 1;
    imprimir_aeropuertos_disponibles();
    string aeropuertoOrigen = consultar_codigo_iata_origen();
    string aeropuertoDestino = consultar_codigo_iata_destino();

    Vertice *inicio = grafo.obtener_vertice_por_elemento(aeropuertoOrigen);
    Vertice *destino = grafo.obtener_vertice_por_elemento(aeropuertoDestino);

    cout << "Aeropuerto origen: " << inicio->obtener_elemento() << endl;
    cout << "Aeropuerto destino: " << destino->obtener_elemento() << endl;

    grafo.obtener_camino_minimo(inicio, destino,opcion);

}
void Menu::vuelo_menor_tiempo() {
    unsigned opcion = 2;
    imprimir_aeropuertos_disponibles();
    string aeropuertoOrigen = consultar_codigo_iata_origen();
    string aeropuertoDestino = consultar_codigo_iata_destino();

    Vertice *inicio = grafo.obtener_vertice_por_elemento(aeropuertoOrigen);
    Vertice *destino = grafo.obtener_vertice_por_elemento(aeropuertoDestino);

    cout << "Aeropuerto origen: " << inicio->obtener_elemento() << endl;
    cout << "Aeropuerto destino: " << destino->obtener_elemento() << endl;

    grafo.obtener_camino_minimo(inicio, destino,opcion);
}

void Menu::imprimir_aeropuertos_disponibles() {
    cout << "Aeropuertos Disponibles para el viaje" << endl;
    for (unsigned int i = 1; i <= grafo.obtener_tam(); i++) {
        cout << i << "---" << grafo.obtener_vertices()->obtener(i)->obtener_elemento()<<"-"<<endl;
    }
}