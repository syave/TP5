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
    T minimo(BSTNode<T>* nodo);
    T maximo(BSTNode<T>* nodo);
    T sucesor(BSTNode<T>* nodo);
    T predecesor(BSTNode<T>* nodo);
    BSTNode<T>* borrar(BSTNode<T>* nodo, T codigo);
    void borrarTodo(BSTNode<T>* nodo);

    int alturaArbol(BSTNode<T>* nodo);
    void imprimirPorNivel(BSTNode<T>* nodo,int nivel);
    void imprimirEnAncho(BSTNode<T>* nodo);
    void imprimirAeropuertos(BSTNode<T>* nodo);

public:
    //metodos

    BST();

    void agregar(T codigo,Aeropuerto* &aeropuerto);

    void imprimirInOrden();

    bool buscar(T codigo);

    void imprimirEnAncho();

    T minimo();

    T maximo();

    T sucesor(T codigo);

    T predecesor(T codigo);

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
    cout<< "Clave: " << nodo->getCodigo()<<std::endl;
	cout << "* Nombre: " + nodo->getAeropuerto()->getNombre()<<std::endl;
	cout << "* Ciudad: " + nodo->getAeropuerto()->getCiudad()<<std::endl;
	cout << "* Pais: " + nodo->getAeropuerto()->getPais()<<std::endl;
	cout << "* Sup: " << nodo->getAeropuerto()->getSuperficie()<<std::endl;
	cout << "* Terminales: " << nodo->getAeropuerto()->getTerminal()<<std::endl;
	cout << "* Destinos Nacionales: " << nodo->getAeropuerto()->getDestinosNacionales()<<std::endl;
	cout << "* Destinos Internacionales: " << nodo->getAeropuerto()->getDestinosInternacionales()<<std::endl;
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
		imprimirAeropuertos(nodo);
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
	/*
	//TODOS LOS AEROPUERTOS
	cout<<"Recorrido Por Ancho"<<endl;
    for (int i=0; i<altura; i++) {
    	imprimirPorNivel(nodo, i);
    }
    cout<<"\n";
    */
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
		return nodo;
	}
}

template <class T>
bool BST<T>::buscar(T codigo) {
    BSTNode<T>* result = buscar(this->raiz, codigo);

    return result != NULL;
}

template <class T>
T BST<T>::minimo(BSTNode<T>* nodo) {
	if(nodo == NULL) {
    	return NULL;
    }else if(nodo->getIzquierda() == NULL){
    	return nodo->getCodigo();
    }else{
    	return minimo(nodo->getIzquierda());
    }
}

template <class T>
T BST<T>::minimo() {
    return minimo(this->raiz);
}

template <class T>
T BST<T>::maximo(BSTNode<T>* nodo) {
	if(nodo == NULL) {
		return NULL;
    }else if(nodo->getDerecha() == NULL) {
    	return nodo->getCodigo();
    }else {
    	return maximo(nodo->getDerecha());
    }
}

template <class T>
T BST<T>::maximo() {
    return maximo(this->raiz);
}

template <class T>
T BST<T>::sucesor(BSTNode<T>* nodo) {
    if (nodo->getDerecha() != NULL) {
        return minimo(nodo->getDerecha());
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
T BST<T>::sucesor(T codigo) {
    BSTNode<T>* codigoNodo = this->buscar(this->raiz, codigo);
    // Return the key. If the key is not found or successor is not found, return -1
    if(codigoNodo == NULL) {
        return NULL;
    }else {
    	return sucesor(codigoNodo);
    }
}

template <class T>
T BST<T>::predecesor(BSTNode<T> * nodo) {
    if (nodo->getIzquierda() != NULL)
    {
        return maximo(nodo->getIzquierda());
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
T BST<T>::predecesor(T codigo) {
    BSTNode<T> * codigoNodo = this->buscar(this->raiz, codigo);

    if(codigoNodo == NULL) {
        return NULL;
    }else{
    	return predecesor(codigoNodo);
    }
}

template <class T>
BSTNode<T> * BST<T>::borrar(BSTNode<T>* nodo, T codigo) {
    // The given node is not found in BST
    if (nodo == NULL)
        return NULL;

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
        // The node has two children (left and right)
        else {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->sucesor(codigo);

            // Replace node's key with successor's key
            nodo->setCodigo(successor_data);

            // Delete the old successor's key
            nodo->setDerecha(borrar(nodo->getDerecha(), successor_data));
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
    this->raiz = borrar(this->raiz, codigo);
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
