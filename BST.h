#include "BSTNode.h"
#include<iostream>
#include <string>
using namespace std;

#ifndef BST_H
#define BST_H

template <class T>
class BST {
private:
    //atributos
    BSTNode<T>* raiz;

    //metodos
    /*
     * Pre : -
     * Post: Agrega al nodo el codigo y su puntero a aeropuerto
     *       Si el codigo es menor a su padre,va a la izquierda,caso contrario a la derecha
     */
    BSTNode<T>* agregar(BSTNode<T>* nodo, T codigo,Aeropuerto* &aeropuerto);

    /*
     * Pre : Nodo distinto de NULL
     * Post: Imprime in orden los datos del aeropuerto del nodo y sus hijos
     */
    void imprimirInOrden(BSTNode<T> * nodo);

    /*
     * Pre : -
     * Post: Busca el codigo dado en el nodo. Si lo encuentra lo devuelve.
     *       Caso contrario devuelve NULL
     */
    BSTNode<T>* buscar(BSTNode<T>* nodo, T codigo);

    /*
     * Pre : -
     * Post: Devuelve el codigo minimo del nodo y sus hijos
     */
    T codigoMinimo(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Devuelve el codigo maximo del nodo y sus hijos
     */
    T codigoMaximo(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Devuelve el codigo sucesor del nodo.Si no hay nodo devuelve NULL
     */
    T codigoSucesor(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Devuelve el codigo predecesor del nodo.Si no hay nodo devuelve NULL
     */
    T codigoPredecesor(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Borra el nodo del codigo dado.
     *       Si el nodo es hoja,borra el nodo y el nodo apunta a NULL
     *       Si el nodo tiene unico hijo izquierdo o derecho,este hijo apuntara a su padre y se borra el nodo
     *       Si tiene 2 hijos,busca el sucesor o predecesor y reemplaza sus valores,y borra el nodo.
     */
    BSTNode<T>* borrar(BSTNode<T>* nodo, T codigo);

    /*
     * Pre : -
     * Post: Borra todos los nodos incluido sus hijos izquierdo y derecho si es que lo tienen
     */
    void borrarTodo(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: DEvuelve la altura del arbol. Si no hay nodo, devuelve NULL
     */
    int alturaArbol(BSTNode<T>* nodo);

    /*
     * Pre : Debe existir la altura del arbol
     * Post: Imprime por nivel los codigos IATA
     */
    void imprimirPorNivel(BSTNode<T>* nodo,int nivel);

    /*
     * Pre : Nodo distinto de NULL. Debe existir altura del arbol
     * Post: Imprime en ancho el codigo del aeropuerto del nodo y sus hijos
     */
    void imprimirEnAncho(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Imprime codigo y datos del aeropuerto del nodo dado
     */
    void imprimirAeropuertos(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Imprime los codigos del nodo dado
     */
    void imprimirCodigos(BSTNode<T>* nodo);

    /*
     * Pre : -
     * Post: Devuelve puntero del sucesor del nodo
     */
    Aeropuerto* aeropuertoSucesor(BSTNode<T>* nodo);

    /*
    * Pre : -
    * Post: Devuelve el puntero del minimo aeropuerto del nodo
    */
    Aeropuerto* minimoAeropuerto(BSTNode<T>* nodo);
public:
    //metodos

    /*
     * Pre : -
     * Post: Inicia el arbol con su atributo raiz vacio
     */
    BST();

    /*
     * Pre : -
     * Post:  LLama a recursiva de agregar
     *        Agrega al nodo,un codigo y un puntero a aeropuerto
     */
    void agregar(T codigo,Aeropuerto* &aeropuerto);

    /*
     * Pre : -
     * Post:   Llama a recursiva de imprimir in orden
     *         Imprime in orden desde la raiz
     */
    void imprimirInOrden();

    /*
     * Pre : -
     * Post: LLama a recursiva de buscar.
     *       Si es NULL,imprime mensaje.Caso contrario devuelve datos del aeropuerto del codigo dado
     */
    void buscar(T codigo);

    /*
     * Pre : -
     * Post: LLama a recursiva de imprimir en ancho.
     *       Imprime en ancho desde la raiz
     */
    void imprimirEnAncho();

    /*
     * Pre : -
     * Post: LLama a recursiva de codigo minimo.
     */
    T codigoMinimo();

    /*
     * Pre : -
     * Post: LLama a recursiva de codigo maximo.
     */
    T codigoMaximo();

    /*
     * Pre : -
     * Post: LLama a recursiva de codigo sucesor dado un codigo.
     */
    T codigoSucesor(T codigo);

    /*
     * Pre : -
     * Post: LLama a recursiva de codigo predecesor dado un codigo.
     */
    T codigoPredecesor(T codigo);

    /*
     * Pre : -
     * Post: Devuelve puntero del aeropuerto del nodo sucesor del codigo
     */
    Aeropuerto* aeropuertoSucesor(T codigo);

    /*
     * Pre : -
     * Post: LLama a recursiva de buscar.
     *       Si lo encuentra lo borra usando recursiva de borrar,sino imprime mensaje de error
     */
    void borrar(T codigo);

    /*
     * Pre : -
     * Post: Devuelve el nodo raiz
     */
    BSTNode<T>* getRaiz();

    /*
     * Pre : -
     * Post: Devuelve true si no hay nodos.caso contrario false
     */
    bool vacio();

    /*
     * Pre : -
     * Post: LLama a recursiva de borrar
     */
    void borrarTodo();

    /*
     * Pre : -
     * Post: Borra todos los nodos del arbol
     */
    ~BST<T>();

};

template <class T>
BST<T>::BST() {
    this->raiz = NULL;
}


template <class T>
BSTNode<T>* BST<T>::agregar(BSTNode<T>* nodo, T codigo,Aeropuerto* &aeropuerto) {

    if (nodo == NULL) {
    	nodo = new BSTNode<T>(codigo,aeropuerto);
    }else if (codigo > nodo->getCodigo()) {
    	nodo->setDerecha(agregar(nodo->getDerecha(), codigo,aeropuerto), nodo);
    }else {
    	nodo->setIzquierda(agregar(nodo->getIzquierda(), codigo,aeropuerto), nodo);
    }
    return nodo;
}

template <class T>
void BST<T>::agregar(T codigo,Aeropuerto* &aeropuerto) {
    this->raiz = agregar(this->raiz, codigo,aeropuerto);
}

template <class T>
void BST<T>::imprimirInOrden(BSTNode<T>* nodo) {
    if (nodo != NULL) {
    	imprimirInOrden(nodo->getIzquierda());
    	imprimirAeropuertos(nodo);
    	imprimirInOrden(nodo->getDerecha());
    }
}

template <class T>
void BST<T>::imprimirInOrden() {
    this->imprimirInOrden(this->raiz);
}

template <class T>
void BST<T>::imprimirAeropuertos(BSTNode<T>* nodo){
    imprimirCodigos(nodo);
    nodo->getAeropuerto()->mostrarAeropuerto();
}

template <class T>
void BST<T>::imprimirCodigos(BSTNode<T>* nodo){
    cout << "--------------------------------------" << endl;
	cout<< "Codigo IATA: " << nodo->getCodigo()<<std::endl;
}


template <class T>
int BST<T>::alturaArbol(BSTNode<T>* nodo) {
	if(nodo == NULL){
		return 0;
	}else {
		int izquierdaAltura = alturaArbol(nodo->getIzquierda());
		int derechaAltura = alturaArbol(nodo->getDerecha());
		if(izquierdaAltura >= derechaAltura){
			return izquierdaAltura + 1;
		}else{
			return derechaAltura + 1;
		}
	}
}

template<class T>
void BST<T>::imprimirPorNivel(BSTNode<T>* nodo,int nivel) {
	if(!nodo){
		return;
	}
	if (nivel == 0){
		imprimirCodigos(nodo);
	}else{
		imprimirPorNivel(nodo->getIzquierda(), nivel - 1);
		imprimirPorNivel(nodo->getDerecha(), nivel - 1);
	}
}

template<class T>
void BST<T>::imprimirEnAncho(BSTNode<T>* nodo) {
	if(!nodo){
		return;
	}
	int altura = alturaArbol(nodo);
	//IMPRESION POR NIVEL
	for (int i=0; i<altura; i++) {
		//cout<<"Nivel " << i<<endl;
		imprimirPorNivel(nodo, i);
	    //cout<<"\n";
	}
}

template<class T>
void BST<T>::imprimirEnAncho() {
	this->imprimirEnAncho(this->raiz);
}

template <class T>
BSTNode<T>* BST<T>::buscar(BSTNode<T>* nodo, T codigo) {
	if(nodo != NULL) {
		if(nodo->getCodigo() == codigo) {
			return nodo;
		}else if(nodo->getCodigo() > codigo){
			return buscar(nodo->getIzquierda(), codigo);
		}else {
			return buscar(nodo->getDerecha(), codigo);
		}
	}else {
		return NULL;
	}
}

template <class T>
void BST<T>::buscar(T codigo) {
	T error = "No se ha encontrado dicho aeropuerto";
	T encontrado = "Se ha encontrado exitosamente el aeropuerto con codigo IATA: ";
	BSTNode<T>* resultado = buscar(this->raiz, codigo);

    if (resultado == NULL) {
    	cout << error <<endl;
    }else {
    	cout << encontrado << resultado->getCodigo() << endl;
    	resultado->getAeropuerto()->mostrarAeropuerto();
    }
}

template <class T>
T BST<T>::codigoMinimo(BSTNode<T>* nodo) {
	if(nodo == NULL) {
    	return NULL;
    }else if(nodo->getIzquierda() == NULL){
    	return nodo->getCodigo();
    }else{
    	return codigoMinimo(nodo->getIzquierda());
    }
}

template <class T>
T BST<T>::codigoMinimo() {
    return codigoMinimo(this->raiz);
}

template <class T>
T BST<T>::codigoMaximo(BSTNode<T>* nodo) {
	if(nodo == NULL) {
		return NULL;
    }else if(nodo->getDerecha() == NULL) {
    	return nodo->getCodigo();
    }else {
    	return codigoMaximo(nodo->getDerecha());
    }
}

template <class T>
T BST<T>::codigoMaximo() {
    return codigoMaximo(this->raiz);
}

template <class T>
T BST<T>::codigoSucesor(BSTNode<T>* nodo) {
    if (nodo->getDerecha() != NULL) {
        return codigoMinimo(nodo->getDerecha());
    }
    BSTNode<T>* sucesor = NULL;
    BSTNode<T>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->getCodigo() < ancestro->getCodigo()) {
        	sucesor = ancestro;
        	ancestro = ancestro->getIzquierda();
        }else {
        	ancestro = ancestro->getDerecha();
        }
    }
    return sucesor->getCodigo();
}

template <class T>
T BST<T>::codigoSucesor(T codigo) {
	BSTNode<T>* codigoNodo = this->buscar(this->raiz, codigo);
	//Regresa el codigo. Si no se encuentra, retorna NULL
    if(codigoNodo == NULL) {
        return NULL;
    }else {
    	return codigoSucesor(codigoNodo);
    }
}

template <class T>
Aeropuerto* BST<T>::minimoAeropuerto(BSTNode<T>* nodo) {
	if(nodo == NULL) {
    	return NULL;
    }else if(nodo->getIzquierda() == NULL){
    	return nodo->getAeropuerto();
    }else{
    	return minimoAeropuerto(nodo->getIzquierda());
    }
}

template <class T>
Aeropuerto* BST<T>::aeropuertoSucesor(BSTNode<T>* nodo) {
    if (nodo->getDerecha() != NULL) {
        return minimoAeropuerto(nodo->getDerecha());
    }
    BSTNode<T>* sucesor = NULL;
    BSTNode<T>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->getAeropuerto() < ancestro->getAeropuerto()) {
        	sucesor = ancestro;
        	ancestro = ancestro->getIzquierda();
        }else {
        	ancestro = ancestro->getDerecha();
        }
    }
    return sucesor->getAeropuerto();
}
template <class T>
Aeropuerto* BST<T>::aeropuertoSucesor(T codigo) {
	BSTNode<T>* codigoNodo = this->buscar(this->raiz, codigo);
    if(codigoNodo == NULL) {
        return NULL;
    }else {
    	return aeropuertoSucesor(codigoNodo);
    }
}

template <class T>
T BST<T>::codigoPredecesor(BSTNode<T> * nodo) {
    if (nodo->getIzquierda() != NULL) {
        return codigoMaximo(nodo->getIzquierda());
    }
    BSTNode<T>* sucesor = NULL;
    BSTNode<T>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->getCodigo() > ancestro->getCodigo()) {
        	sucesor = ancestro; // Ultimo nodo,en el que el nodo actual esta en la izquierda
        	ancestro = ancestro->getDerecha();
        }
        else
        	ancestro = ancestro->getIzquierda();
    }
    return sucesor->getCodigo();
}

template <class T>
T BST<T>::codigoPredecesor(T codigo) {
    BSTNode<T> * codigoNodo = this->buscar(this->raiz, codigo);

    if(codigoNodo == NULL) {
        return NULL;
    }else{
    	return codigoPredecesor(codigoNodo);
    }
}

template <class T>
BSTNode<T> * BST<T>::borrar(BSTNode<T>* nodo, T codigo) {
    if (nodo->getCodigo() == codigo) {
        if (nodo->esHoja()) {
            delete nodo;
            nodo = NULL;
        }else if (nodo->unicoHijoDerecho()) {
            //Unico hijo estara conectado a su padre directamente
        	nodo->getDerecha()->setPadre(nodo->getPadre());
            BSTNode<T>* aux = nodo;
            nodo = nodo->getDerecha();
            delete aux;
        }else if (nodo->unicoHijoIzquierdo()) {
            //Unico hijo estara conectado a su padre directamente
        	nodo->getIzquierda()->setPadre(nodo->getPadre());
            BSTNode<T>* aux = nodo;
            nodo = nodo->getIzquierda();
            delete aux;
        }
        else {  //Nodo con 2 hijos
            // Encuentro sucesor o predecesor para evitar problemas
            T codigoSucesor = this->codigoSucesor(codigo);
            Aeropuerto* aeropuertoSucesor = this->aeropuertoSucesor(codigo);
            //Encuentro puntero a aeropuerto del nodo
            Aeropuerto* aeropuerto = nodo->getAeropuerto();

            //Reemplazo el nodo con los valores del sucesor
            nodo->setAeropuerto(aeropuertoSucesor);
            nodo->setCodigo(codigoSucesor);

            //Borro datos del anterior sucesor y aeropuerto
            nodo->setDerecha(borrar(nodo->getDerecha(), codigoSucesor));
            delete aeropuerto;
        }
    }else if (nodo->getCodigo() < codigo){
    	nodo->setDerecha(borrar(nodo->getDerecha(), codigo));
    }else {
    	nodo->setIzquierda(borrar(nodo->getIzquierda(), codigo));
    }
    return nodo;
}

template <class T>
void BST<T>::borrar(T codigo) {
	T error = "Dicho aeropuerto no existe por lo tanto no se pudo borrar";
	T borradoExitoso = "Se elimino el aeropuerto con codigo IATA ";
	BSTNode<T>* resultado = buscar(this->raiz, codigo);

    if (resultado == NULL) {
    	cout << error <<endl;
    }else {
    	this->raiz = borrar(this->raiz, codigo);
    	cout << borradoExitoso<< codigo <<endl;
    }
}

template <class T>
BSTNode<T>* BST<T>::getRaiz(){
    return this->raiz;
}

template <class T>
bool BST<T>::vacio() {
    return this->raiz == NULL;
}


template <class T>
void BST<T>::borrarTodo(BSTNode<T>* nodo) {
    if(nodo == NULL)
        return;
    this->borrarTodo(nodo->getIzquierda());
    this->borrarTodo(nodo->getDerecha());
    delete nodo;
}

template <class T>
void BST<T>::borrarTodo() {
    this->borrarTodo(this->raiz);
}

template <class T>
BST<T>::~BST<T>() {
	this->borrarTodo();
}


#endif //ABB_BST_H
