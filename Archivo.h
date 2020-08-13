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
	Archivo();
	~Archivo();

	void cargarArchivo(BST<string> &bst);
};

#endif /* ARCHIVO_H_ */
