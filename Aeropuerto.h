#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <string>
using namespace std;

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
    /*
    * Pre : -
    * Post: Inicia el Aeropuerto con sus atributos vacios.
    */
    Aeropuerto();

    /*
    * Pre : -
    * Post: Destructor
    */
    ~Aeropuerto();

    /*
    * Pre : -
    * Post: Cambia el nombre del aeropuerto.
    */
    void setNombre(string nombre);

    /*
    * Pre : -
    * Post: Devuelve el nombre del aeropuerto.
    */
    string getNombre();

    /*
    * Pre : -
    * Post: Cambia el nombre de la ciudad.
    */
    void setCiudad(string ciudad);

    /*
    * Pre : -
    * Post: Devuelve el nombre de la ciudad.
    */
    string getCiudad();

    /*
    * Pre : -
    * Post: Cambia el nombre del pais.
    */
    void setPais(string pais);

    /*
    * Pre : -
    * Post: Devuelve el nombre del pais.
    */
    string getPais();

    /*
    * Pre : -
    * Post: Cambia la superficie.
    */
    void setSuperficie(double superficie);

    /*
    * Pre : -
    * Post: Devuelve la superficie.
    */
    double getSuperficie();

    /*
    * Pre : -
    * Post: Cambia la terminal.
    */
    void setTerminal(int terminal);

    /*
    * Pre : -
    * Post: Devuelve la terminal.
    */
    unsigned getTerminal();

    /*
    * Pre : -
    * Post: Cambia los destinos nacionales.
    */
    void setDestinosNacionales(int destinosNacionales);

    /*
    * Pre : -
    * Post: Devuelve los destinos nacionales.
    */
    unsigned getDestinosNacionales();

    /*
    * Pre : -
    * Post: Cambia los destinos internacionales.
    */
    void setDestinosInternacionales(int DestinosInternaciones);

    /*
    * Pre : -
    * Post: Devuelve los destinos internacionales.
    */
    unsigned getDestinosInternacionales();

    /*
    * Pre : -
    * Post: Muestra todos los datos del aeropuerto.
    */
    void mostrarAeropuerto();

};


#endif //AEROPUERTO_H
