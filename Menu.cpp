#include "Menu.h"

Menu::Menu() {
	entrada = 0;
}

Menu::~Menu() {

}

void Menu::mostrarMenu() {
	cargarAeropuertos();
	while (entrada != 6) {
		menuOpciones();
		cin >> entrada;
		validarEntrada(entrada, 6);
		switch (entrada) {
		case 1: //consulta aeropuerto
			consultarAeropuerto();
			break;
		case 2: //nuevo aeropuerto
			agregarAeropuerto();
			break;
		case 3: //borrar aeropuerto
			eliminarAeropuerto();
			break;
		case 4: //recorrido in orden
			recorridoInOrden();
			break;
		case 5: //recorrido en ancho
			recorridoEnAncho();
			break;
		case 6: //salir
			limpiarPantalla();

		}
	}
}

void Menu::agregarAeropuerto() {
	string codigo,nombre,ciudad,pais;
	double superficie;
	unsigned terminal,daestinosNacionales,destinosInternacionales;
	Aeropuerto* aeropuerto = new Aeropuerto;
	cout << "Ingrese el codigo IATA: ";
	cin >> codigo;
	cout << "Ingrese el nombre del aeropuerto: ";
	cin >> nombre;
	cout << "Ingrese el pais del aeropuerto: ";
	cin >> pais;
	cout << "Ingrese la ciudad del aeropuerto: ";
	cin >> ciudad;
	cout << "Ingrese la superficie del aeropuerto: ";
	cin >> superficie;
	cout << "Ingrese la cantidad de terminales del aeropuerto: ";
	cin >> terminal;
	cout << "Ingrese la cantidad de destinos nacionales: ";
	cin >> daestinosNacionales;
	cout << "Ingrese la cantidad de destinos internacionales: ";
	cin >> destinosInternacionales;
	aeropuerto->setCiudad(ciudad);
	aeropuerto->setNombre(nombre);
	aeropuerto->setPais(pais);
	aeropuerto->setSuperficie(superficie);
	aeropuerto->setTerminal(terminal);
	aeropuerto->setDestinosNacionales(daestinosNacionales);
	aeropuerto->setDestinosInternacionales(destinosInternacionales);
	bst.agregar(codigo, aeropuerto);
	cout << "Se agrego el Aeropuerto " << aeropuerto->getNombre() << endl;
}

void Menu::eliminarAeropuerto() {
	string codigo;
	cout << "Ingrese el codigo IATA del aeropuerto: ";
	cin >> codigo;
	bst.borrar(codigo);
}

void Menu::recorridoEnAncho() {
	bst.imprimirEnAncho();
}

void Menu::recorridoInOrden() {
	bst.imprimirInOrden();
}

void Menu::consultarAeropuerto() {
	string codigo,resultadoBusqueda;
	cout << "Ingrese el codigo IATA del aeropuerto a consultar: ";
	cin >> codigo;
	bst.buscar(codigo);
}

void Menu::cargarAeropuertos() {
	archivo.cargarArchivo(bst);
}
void Menu::limpiarPantalla(){

	#ifdef linux
    		system("clear");
	#else
    		system ("cls");
	#endif
}

void Menu::menuOpciones() {
	cout << "--------------------------------------" << endl;
	cout << "TP5" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Por favor introduzca una opcion: " << endl;
	cout << 	" -1) Consultar por un aeropuerto.\n"
			" -2) Dar de alta un nuevo Aeropuerto.\n"
			" -3) Dar de baja un Aeropuerto.\n"
			" -4) Mostrar todos los Aeropuertos(In Orden).\n"
			" -5) Mostrar todos los Aeropuertos(En Ancho).\n"
			" -6) Salir.\n";
	cout << "--------------------------------------" << endl;
	cout << "Entrada: ";
}

void Menu::validarEntrada(unsigned &entrada, unsigned corte) {
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

void Menu::mensaje(){
	cout << "Entrada no valida.Por favor Intente de nuevo.\n";
}

