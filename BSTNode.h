#ifndef BSTNODE_H
#define BSTNODE_H

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
    /*
     * Pre : -
     * Post: Inicia nodo del arbol con el codigo y puntero a aeropuerto
     *       Los demas atributos vacios
     */
    BSTNode(T codigo,Aeropuerto* aeropuerto);

    /*
     * Pre : -
     * Post: Devuelve el codigo del aeropuerto
     */
    string getCodigo();

    /*
    * Pre : -
    * Post: Devuelve el puntero del aeropuerto.
    */
    Aeropuerto* getAeropuerto();

    /*
     * Pre : -
     * Post: Cambia el codigo del aeropuerto.
     */
    void setCodigo(T codigo);

    /*
     * Pre : -
     * Post: Cambia el puntero del aeropuerto.
     */
    void setAeropuerto(Aeropuerto* aeropuerto);

    /*
     * Pre : -
     * Post: Cambia el hijo derecho del nodo junto a su padre.
     */
    void setDerecha(BSTNode<T>* derecha, BSTNode<T>* padre);

    /*
     * Pre : -
     * Post: Cambia el hijo izquierdo del nodo junto a su padre.
     */
    void setIzquierda(BSTNode<T>* izquierda, BSTNode<T>* padre);

    /*
     * Pre : -
     * Post: Cambia el hijo izquierdo del nodo.
     */
    void setIzquierda(BSTNode<T>* izquierda);

    /*
     * Pre : -
     * Post: Cambia el hijo derecho del nodo.
     */
    void setDerecha(BSTNode<T>* derecha);

    /*
     * Pre : -
     * Post: Cambia el padre del nodo.
     */
    void setPadre(BSTNode<T>* padre);

    /*
     * Pre : -
     * Post: Devuelve el puntero al hijo derecho del nodo
     */
    BSTNode<T>* getDerecha();

    /*
     * Pre : -
     * Post: Devuelve el puntero al hijo izquierdo del nodo
     */
    BSTNode<T>* getIzquierda();

    /*
     * Pre : -
     * Post: Devuelve el puntero al padre del nodo
     */
    BSTNode<T>* getPadre();

    /*
     * Pre : -
     * Post: Devuelve true si no tiene hijo izquierdo ni derecho,caso contrario false
     */
    bool esHoja();

    /*
     * Pre : -
     * Post: Devuelve true si tiene hijo izquierdo pero no derecho,caso contrario false
     */
    bool unicoHijoDerecho();

    /*
     * Pre : -
     * Post: Devuelve true si tiene hijo izquierdo pero no izquierdo,caso contrario false
     */
    bool unicoHijoIzquierdo();

    /*
    * Pre : -
    * Post: Elimina aeropuerto del nodo
    */
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
void BSTNode<T>::setAeropuerto(Aeropuerto* aeropuerto){
	this->aeropuerto = aeropuerto;
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
    delete this->aeropuerto;
}

#endif //ABB_BSTNODE_H
