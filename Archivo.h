#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include "Aeropuerto.h"
#include "BST.h"
#include <fstream>
#include<iostream>

const string NOMBRE_ARCHIVO = "aeropuertos.txt";

class Archivo {
private:
	Aeropuerto* puntero;
	ifstream archivo;
public:

    /*
    * Pre : -
    * Post: Inicia el archivo con sus atributos vacios.
    */
	Archivo();

    /*
    * Pre : -
    * Post: Destructor.
    */
	~Archivo();

    /*
    * Pre : -
    * Post: Carga desde el archivo indicado los elementos.
    */
	void cargarArchivo(BST<string> &bst);
};

#endif /* ARCHIVO_H_ */
