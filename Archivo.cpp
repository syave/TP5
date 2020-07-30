#include "Archivo.h"

Archivo::Archivo() {
	archivo.open(NOMBRE_ARCHIVO);
	puntero = 0;
}

Archivo::~Archivo() {

}

void Archivo::cargarArchivo(BST<string> &bst) {
	double sup;
	unsigned terminal,destinosNacional,destinosInternacional;
	string nombre,ciudad,pais;
	string codigo;

	if(!archivo.fail()) {
		while (archivo >> codigo) {
			puntero = new Aeropuerto();
            archivo >> nombre;
            puntero->setNombre(nombre);
            archivo >> ciudad;
            puntero->setCiudad(ciudad);
            archivo >> pais;
            puntero->setPais(pais);
            archivo >> sup;
            puntero->setSuperficie(sup);
            archivo >> terminal;
            puntero->setTerminal(terminal);
            archivo >> destinosNacional;
            puntero->setDestinosNacionales(destinosNacional);
            archivo >> destinosInternacional;
            puntero->setDestinosInternacionales(destinosInternacional);
            bst.agregar(codigo, puntero);
		}
	}else {
		cout << "No hay archivo" <<endl;
	}
	puntero = 0;
	delete puntero;
	archivo.close();
}

