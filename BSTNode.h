#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H

#include <string>
#include "Aeropuerto.h"

using namespace std;

template <class T>
class BSTNode
{
private:
    string codigo;
    Aeropuerto *aeropuerto;
    BSTNode<T>* left; //Left children
    BSTNode<T>* right; //Right children
    BSTNode<T>* parent;

public:
    BSTNode(string codigo,Aeropuerto* aeropuerto);
    T get_codigo();
    Aeropuerto* get_aeropuerto();
    void set_codigo(string codigo);
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left);
    void set_right(BSTNode<T>* right);
    void set_parent(BSTNode<T>* parent);
    BSTNode<T>* get_right();
    BSTNode<T>* get_left();
    BSTNode<T>* get_parent();
    bool isLeaf();
    bool rightChildOnly();
    bool leftChildOnly();
};

template <class T>
BSTNode<T>::BSTNode(string codigo,Aeropuerto* aeropuerto)
{
    this->codigo = codigo;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->aeropuerto = aeropuerto;
}

template <class T>
T BSTNode<T>::get_codigo()
{
    return this->codigo;
}

template <class T>
Aeropuerto* BSTNode<T>::get_aeropuerto() {
    return this->aeropuerto;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right, BSTNode<T>* parent){
    this->right = right;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right){
    this->right = right;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left, BSTNode<T>* parent){
    this->left = left;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_parent(BSTNode<T> *parent) {
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_codigo(string codigo) {
    this->codigo = codigo;
}


template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left){
    this->left = left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_right()
{
    return this->right;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_left()
{
    return this->left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_parent()
{
    return this->parent;
}

template <class T>
bool BSTNode<T>::isLeaf() {
    return (this->get_left() == NULL && this->get_right() == NULL);
}

template <class T>
bool BSTNode<T>::rightChildOnly() {
    return (this->get_left() == NULL && this->get_right() != NULL);
}

template <class T>
bool BSTNode<T>::leftChildOnly() {
    return (this->get_left() != NULL && this->get_right() == NULL);
}

#endif //ABB_BSTNODE_H
