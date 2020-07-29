#include<iostream>
#include <fstream>
#include "BST.h"
//#include "Archivo.h"
#include <string>

using namespace std;
const string NOMBRE_ARCHIVO = "aeropuertos.txt";

int main() {


	BST<string>* bst = new BST<string>();

    double sup;
    unsigned terminal,destinosNacional,destinosInternacional;
    string nombre,ciudad,pais;
    string codigo;
    Aeropuerto* puntero;
    puntero = new Aeropuerto();
    ifstream archivo;
    archivo.open(NOMBRE_ARCHIVO);
    if(!archivo.fail()) {
        while (!archivo.eof()) {
        	archivo >> codigo;
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
            bst->insert(codigo, puntero);
        }
    archivo.close();
    }else{
        cout << "No hay archivo" <<endl;
    }


    //In order
    bst->print_in_order();

    delete bst;
}

