#include<iostream>
#include <fstream>
#include "BST.h"
//#include "Archivo.h"
#include <string>

using namespace std;
const string NOMBRE_ARCHIVO = "aeropuertos.txt";

int main() {
    double s;
    unsigned t,dN,dI;
    string n,c,p;
    string code;
    //Aeropuerto* puntero;
    BST<string>* bst = new BST<string>();
    ifstream archivo;
    archivo.open(NOMBRE_ARCHIVO);
    if(!archivo.fail()) {
        while (!archivo.eof()) {
        	Aeropuerto auxiliar;
            archivo >> code;
            archivo >> n;
            auxiliar.setNombre(n);
            archivo >> c;
            auxiliar.setCiudad(c);
            archivo >> p;
            auxiliar.setPais(p);
            archivo >> s;
            auxiliar.setSuperficie(s);
            archivo >> t;
            auxiliar.setTerminal(t);
            archivo >> dN;
            auxiliar.setDestinosNacionales(dN);
            archivo >> dI;
            auxiliar.setDestinosInternacionales(dI);
            bst->insert(code, auxiliar);
        }
    archivo.close();
    }else{
        cout << "No hay archivo" <<endl;
    }
    bst->print_in_order();

    delete bst;
}

