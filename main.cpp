#include<iostream>

#include "BST.h"
#include "Archivo.h"

using namespace std;

int main() {
//------------------------BST--------------------------------------//

	Archivo archivo;
	BST<string> bst;

	archivo.cargarArchivo(bst);

	//Borrar Aeropuerto------EN PROGRESO

	//Agregar aeropuerto-----FUNCIONA

    //In orden-----FUNCIONA
    //bst.imprimirInOrden();

    //En Ancho-------FUNCIONA
	//bst.imprimirEnAncho();

	//Busqueda------FUNCIONA,PERO MODIFICAR PARA QUE TIRE EL CODIGO Y NO BOOLEANO
	//cout<<bst.buscar("EZE")<<endl;

}

