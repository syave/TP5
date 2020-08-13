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

	codigo = obtenerCodigoIata();
	nombre = obtenerNombreAeropuerto();
    pais = obtenerPais();
    ciudad = obtenerCiudad();
    superficie = obtenerSuperficie();
    terminal = obtenerTerminales();
    daestinosNacionales = obtenerDestinosNacionales();
    destinosInternacionales = obtenerDestinosInternacionales();

    cargarDatos(codigo,nombre,ciudad,pais,superficie,terminal,daestinosNacionales,destinosInternacionales);
}

void Menu::eliminarAeropuerto() {
	string codigo;
	codigo = obtenerCodigoIata();
    diccionario.borrar(codigo);
}

void Menu::recorridoEnAncho() {
    diccionario.imprimirEnAncho();
}

void Menu::recorridoInOrden() {
    diccionario.imprimirInOrden();
}

void Menu::consultarAeropuerto() {
	string codigo;
    codigo = obtenerCodigoIata();
    diccionario.buscar(codigo);
}

void Menu::cargarAeropuertos() {
	archivo.cargarArchivo(diccionario);
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

string Menu::obtenerCodigoIata() {
    string codigo;
    cout << "Ingrese el codigo IATA del aeropuerto: ";
    cin >> codigo;
    return codigo;
}
string Menu::obtenerNombreAeropuerto() {
    string nombre;
    cout << "Ingrese el nombre del aeropuerto: ";
    cin >> nombre;
    return nombre;
}
string Menu::obtenerPais() {
    string pais;
    cout << "Ingrese el pais del aeropuerto: ";
    cin >> pais;
    return pais;
}
string Menu::obtenerCiudad() {
    string ciudad;
    cout << "Ingrese la ciudad del aeropuerto: ";
    cin >> ciudad;
    return ciudad;
}

double Menu::obtenerSuperficie() {
    double superficie;
    cout << "Ingrese la superficie del aeropuerto: ";
    cin >> superficie;
}

unsigned Menu::obtenerTerminales() {
    unsigned terminal;
    cout << "Ingrese la cantidad de terminales del aeropuerto: ";
    cin >> terminal;
    return terminal;
}

unsigned Menu::obtenerDestinosNacionales() {
    unsigned daestinosNacionales;
    cout << "Ingrese la cantidad de destinos nacionales: ";
    cin >> daestinosNacionales;
    return daestinosNacionales;
}

unsigned Menu::obtenerDestinosInternacionales() {
    unsigned destinosInternacionales;
    cout << "Ingrese la cantidad de destinos internacionales: ";
    cin >> destinosInternacionales;
    return destinosInternacionales;
}

void Menu::cargarDatos(string codigo,string nombre,string ciudad,string pais,double superficie,unsigned terminal,unsigned daestinosNacionales,unsigned destinosInternacionales) {
    Aeropuerto* aeropuerto = new Aeropuerto;
    aeropuerto->setCiudad(ciudad);
    aeropuerto->setNombre(nombre);
    aeropuerto->setPais(pais);
    aeropuerto->setSuperficie(superficie);
    aeropuerto->setTerminal(terminal);
    aeropuerto->setDestinosNacionales(daestinosNacionales);
    aeropuerto->setDestinosInternacionales(destinosInternacionales);
    diccionario.agregar(codigo, aeropuerto);
    cout << "Se agrego el Aeropuerto " << aeropuerto->getNombre() << endl;
}

