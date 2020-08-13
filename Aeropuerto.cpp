#include "Aeropuerto.h"
#include <iostream>

Aeropuerto::Aeropuerto() {
    nombre = "";
    ciudad = "";
    pais = "";
    superficie = 0;
    terminal = 0;
    destinosNacionales = 0;
    destinosInternacionales = 0;
}

Aeropuerto::~Aeropuerto() {}

void Aeropuerto::setNombre(string nombre) {
    this->nombre = nombre;
}
string Aeropuerto::getNombre() {
    return nombre;
}

void Aeropuerto::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}
string Aeropuerto::getCiudad() {
    return ciudad;
}

void Aeropuerto::setPais(string pais) {
    this->pais = pais;
}
string Aeropuerto::getPais() {
    return pais;
}

void Aeropuerto::setSuperficie(double superficie) {
    this->superficie = superficie;
}
double Aeropuerto::getSuperficie() {
    return superficie;
}

void Aeropuerto::setTerminal(int terminal) {
    this->terminal = terminal;
}
unsigned Aeropuerto::getTerminal() {
    return terminal;
}

void Aeropuerto::setDestinosNacionales(int destinosNacionales) {
    this->destinosNacionales = destinosNacionales;
}
unsigned Aeropuerto::getDestinosNacionales() {
    return destinosNacionales;
}

void Aeropuerto::setDestinosInternacionales(int DestinosInternaciones) {
    this->destinosInternacionales = DestinosInternaciones;
}
unsigned Aeropuerto::getDestinosInternacionales() {
    return destinosInternacionales;
}

void Aeropuerto::mostrarAeropuerto() {
    cout << "--------------------------------------" << endl;
	cout << "* Nombre: " + getNombre()<<endl;
	cout << "* Ciudad: " + getCiudad()<<endl;
	cout << "* Pais: " + getPais()<<endl;
	cout << "* Sup: " << getSuperficie()<<endl;
	cout << "* Terminales: " << getTerminal()<<endl;
	cout << "* Destinos Nacionales: " << getDestinosNacionales()<<endl;
	cout << "* Destinos Internacionales: " << getDestinosInternacionales()<<endl;
}
