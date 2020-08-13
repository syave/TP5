#ifndef MENU_H_
#define MENU_H_

#include "BST.h"
#include "Archivo.h"

class Menu {
private:
	Archivo archivo;
	BST<string> diccionario;
	unsigned entrada;

public:
    /*
     * Pre : -
     * Post: Inicia el menu con sus atributos vacios.
     */
	Menu();

    /*
     * Pre : -
     * Post: Destructor.
     */
	~Menu();

    /*
     * Pre : -
     * Post: Muestra en pantalla la lista de opciones.
     */
	void mostrarMenu();

    /*
     * Pre : -
     * Post: Limpia la pantalla.
     */
	void limpiarPantalla();

    /*
     * Pre : -
     * Post: LLama a las funciones para obtener datos del usuario y cargarDatos para agregar el aeropuerto
     */
	void agregarAeropuerto();

    /*
     * Pre : -
     * Post: Elimina el aeropuerto del codigo dado por el usuario.
     */
    void eliminarAeropuerto();

    /*
     * Pre : -
     * Post: Imprime el recorrido in orden.
     */
    void recorridoInOrden();

    /*
     * Pre : -
     * Post: Imprime el recorrido en ancho.
     */
	void recorridoEnAncho();

    /*
     * Pre : -
     * Post: Busca el codigo dado por el usuario.Devuelve datos si lo encuentra,sino mensaje de no encontrado.
     */
    void consultarAeropuerto();
private:

    /*
     * Pre : -
     * Post: Muestra en pantalla las opciones.
     */
	void menuOpciones();
    /*
     * Pre : -
     * Post: Valida la entrada por el usuario.Si la entrada esta fuera del rango,llama a verificacion.
     */
    void validarEntrada(unsigned &, unsigned);

    /* Pre : -
     * Post: Manda mensaje de error y solicita al usuario una nueva entrada.
     */
    void verificar(unsigned &);

    /*
     * Pre : -
     * Post: Imprime el texto de error.
     */
    void mensaje();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
	string obtenerCodigoIata();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
	string obtenerNombreAeropuerto();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
	string obtenerCiudad();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
	string obtenerPais();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
	double obtenerSuperficie();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
    unsigned obtenerTerminales();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
    unsigned obtenerDestinosNacionales();

    /*
     * Pre : -
     * Post: Devuelve dato otorgado por el usuario.
     */
    unsigned obtenerDestinosInternacionales();

    /*
     * Pre : -
     * Post: Carga los datos otorgados por el usuario
     */
    void cargarDatos(string,string,string,string,double ,unsigned ,unsigned ,unsigned );

    /*
     * Pre : -
     * Post: Carga los aeropuertos.
     */
    void cargarAeropuertos();

};

#endif /* MENU_H_ */
