#include "BSTNode.h"
#include<iostream>
#include <string>
using namespace std;

#ifndef ABB_BST_H
#define ABB_BST_H

template <class T>
class BST {
private:
    //atributos
    BSTNode<T>* raiz;

    //metodos
    BSTNode<T>* agregar(BSTNode<T>* nodo, T codigo,Aeropuerto* &aeropuerto);
    void imprimirInOrden(BSTNode<T> * nodo);
    BSTNode<T>* buscar(BSTNode<T>* nodo, T codigo);
    T codigoMinimo(BSTNode<T>* nodo);
    T codigoMaximo(BSTNode<T>* nodo);
    T codigoSucesor(BSTNode<T>* nodo);
    T codigoPredecesor(BSTNode<T>* nodo);
    BSTNode<T>* borrar(BSTNode<T>* nodo, T codigo);
    void borrarTodo(BSTNode<T>* nodo);

    int alturaArbol(BSTNode<T>* nodo);
    void imprimirPorNivel(BSTNode<T>* nodo,int nivel);
    void imprimirEnAncho(BSTNode<T>* nodo);
    void imprimirAeropuertos(BSTNode<T>* nodo);
    void imprimirCodigos(BSTNode<T>* nodo);
    Aeropuerto* aeropuertoSucesor(BSTNode<T>* nodo);
    //Aeropuerto* aeropuertoPredecesor(BSTNode<T>* nodo);
    Aeropuerto* minimoAeropuerto(BSTNode<T>* nodo);
    //Aeropuerto* maximoAeropuerto(BSTNode<T>* nodo);
public:
    //metodos

    BST();

    void agregar(T codigo,Aeropuerto* &aeropuerto);

    void imprimirInOrden();

    void buscar(T codigo);

    void imprimirEnAncho();

    T codigoMinimo();

    T codigoMaximo();

    T codigoSucesor(T codigo);

    T codigoPredecesor(T codigo);

    //Puntero al aeropuerto del nodo sucesor
    Aeropuerto* aeropuertoSucesor(T codigo);
    //Aeropuerto* aeropuertoPredecesor(T codigo);

    void borrar(T codigo);

    BSTNode<T>* getRaiz();
    bool vacio();

    void borrarTodo();
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
    cout<< "Codigo IATA: " << nodo->getCodigo()<<std::endl;
    nodo->getAeropuerto()->mostrarAeropuerto();
}

template <class T>
void BST<T>::imprimirCodigos(BSTNode<T>* nodo){
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
		cout<<"Nivel " << i<<endl;
		imprimirPorNivel(nodo, i);
	    cout<<"\n";
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
    // Return the key. If the key is not found or successor is not found, return -1
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
        	sucesor = ancestro; // so far this is the deepest node for which current node is in left
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
            nodo = NULL;
            //nodo->getAeropuerto() == NULL;
        }else if (nodo->unicoHijoDerecho()) {
            // The only child will be connected to the parent's of node directly
        	nodo->getDerecha()->setPadre(nodo->getPadre());
            // Bypass node
            BSTNode<T>* aux = nodo;
            nodo = nodo->getDerecha();
            delete aux;
        }else if (nodo->unicoHijoIzquierdo()) {
            // The only child will be connected to the parent's of node directly
        	nodo->getIzquierda()->setPadre(nodo->getPadre());
            // Bypass node
            BSTNode<T>* aux = nodo;
            nodo = nodo->getIzquierda();
            delete aux;
        }
        else {  //Nodo con 2 hijos
            // Find successor or predecessor to avoid quarrel
            T codigoSucesor = this->codigoSucesor(codigo);
            Aeropuerto* aeropuertoSucesor = this->aeropuertoSucesor(codigo);

            //Reemplazo el nodo con los valores del sucesor
            nodo->setAeropuerto(aeropuertoSucesor);
            nodo->setCodigo(codigoSucesor);

            //Borro datos del anterior sucesor
            nodo->setDerecha(borrar(nodo->getDerecha(), codigoSucesor));
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
	borrarTodo();
}


#endif //ABB_BST_H
