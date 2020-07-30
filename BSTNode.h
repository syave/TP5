#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H

#include <string>
#include "Aeropuerto.h"

using namespace std;

template <class T>
class BSTNode {
private:
    T codigo;
    Aeropuerto* aeropuerto;
    BSTNode<T>* izquierda; //Hijo izquierda
    BSTNode<T>* derecha; //Hijo derecha
    BSTNode<T>* padre;

public:
    BSTNode(T codigo,Aeropuerto* aeropuerto);
    string getCodigo();
    Aeropuerto* getAeropuerto();
    void setCodigo(T codigo);
    void setDerecha(BSTNode<T>* derecha, BSTNode<T>* padre);
    void setIzquierda(BSTNode<T>* izquierda, BSTNode<T>* padre);
    void setIzquierda(BSTNode<T>* izquierda);
    void setDerecha(BSTNode<T>* derecha);
    void setPadre(BSTNode<T>* padre);
    BSTNode<T>* getDerecha();
    BSTNode<T>* getIzquierda();
    BSTNode<T>* getPadre();
    bool esHoja();
    bool unicoHijoDerecho();
    bool unicoHijoIzquierdo();
    ~BSTNode();
};

template <class T>
BSTNode<T>::BSTNode(T codigo,Aeropuerto* aeropuerto) {
    this->codigo = codigo;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
    this->aeropuerto = aeropuerto;
}

template <class T>
string BSTNode<T>::getCodigo() {
    return this->codigo;
}

template <class T>
Aeropuerto* BSTNode<T>::getAeropuerto() {
    return this->aeropuerto;
}

template <class T>
void BSTNode<T>::setDerecha(BSTNode<T>* derecha, BSTNode<T>* padre){
    this->derecha = derecha;
    this->padre = padre;
}

template <class T>
void BSTNode<T>::setDerecha(BSTNode<T>* derecha){
    this->derecha = derecha;
}

template <class T>
void BSTNode<T>::setIzquierda(BSTNode<T>* izquierda, BSTNode<T>* padre){
    this->izquierda = izquierda;
    this->padre = padre;
}

template <class T>
void BSTNode<T>::setPadre(BSTNode<T> *padre) {
    this->padre = padre;
}

template <class T>
void BSTNode<T>::setCodigo(T codigo) {
    this->codigo = codigo;
}


template <class T>
void BSTNode<T>::setIzquierda(BSTNode<T>* izquierda){
    this->izquierda = izquierda;
}

template <class T>
BSTNode<T>* BSTNode<T>::getDerecha() {
    return this->derecha;
}

template <class T>
BSTNode<T>* BSTNode<T>::getIzquierda() {
    return this->izquierda;
}

template <class T>
BSTNode<T>* BSTNode<T>::getPadre() {
    return this->padre;
}

template <class T>
bool BSTNode<T>::esHoja() {
    return (this->getIzquierda() == NULL && this->getDerecha() == NULL);
}

template <class T>
bool BSTNode<T>::unicoHijoDerecho() {
    return (this->getIzquierda() == NULL && this->getDerecha() != NULL);
}

template <class T>
bool BSTNode<T>::unicoHijoIzquierdo() {
    return (this->getIzquierda() != NULL && this->getDerecha() == NULL);
}
template <class T>
BSTNode<T>::~BSTNode() {
    delete aeropuerto;
}

#endif //ABB_BSTNODE_H
