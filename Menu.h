#ifndef MENU_H_
#define MENU_H_

#include "BST.h"
#include "Archivo.h"

class Menu {
private:
	Archivo archivo;
	BST<string> bst;
	unsigned entrada;

public:
	Menu();
	~Menu();

	void mostrarMenu();
	void limpiarPantalla();

	void cargarAeropuertos();
	void agregarAeropuerto();
	void eliminarAeropuerto();
	void recorridoInOrden();
	void recorridoEnAncho();
	void consultarAeropuerto();
private:

	void mensaje();
	void menuOpciones();
	void validarEntrada(unsigned &, unsigned);
	void verificar(unsigned &);

};

#endif /* MENU_H_ */
