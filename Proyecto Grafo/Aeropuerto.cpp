#include "Aeropuerto.h"

Aeropuerto::Aeropuerto() {
    this->codigo = "";
}
Aeropuerto::~Aeropuerto() {};

void Aeropuerto::set_codigo(string codigo) {
    this->codigo = codigo;
}

string Aeropuerto::get_codigo() {
    return this->codigo;
}