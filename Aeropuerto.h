#ifndef AEROPUERTO_H
#define AEROPUERTO_H

using namespace std;
#include <string>

class Aeropuerto {
private:
    string nombre;
    string ciudad;
    string pais;
    double superficie;
    unsigned terminal;
    unsigned destinosNacionales;
    unsigned destinosInternacionales;
public:
    Aeropuerto();
    ~Aeropuerto();
    void setNombre(string nombre);
    string getNombre();

    void setCiudad(string ciudad);
    string getCiudad();

    void setPais(string pais);
    string getPais();

    void setSuperficie(double superficie);
    double getSuperficie();

    void setTerminal(int terminal);
    unsigned getTerminal();

    void setDestinosNacionales(int destinosNacionales);
    unsigned getDestinosNacionales();

    void setDestinosInternacionales(int DestinosInternaciones);
    unsigned getDestinosInternacionales();

    void mostrarAeropuerto();

};


#endif //AEROPUERTO_H
