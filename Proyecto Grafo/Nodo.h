#ifndef NODO_H_
#define NODO_H_

template <class T> class Nodo {
  private:
    T dato;
    Nodo<T>* siguiente;
    unsigned int prioridad;

  public:

    // POST: El Nodo resulta inicializado con el dato dado y sin un Nodo siguiente.
    Nodo(T dato);

    Nodo(T dato, unsigned int prioridad);

    // POST: Devuelve el valor del dato.
    T obtener_dato();

    // POST: Cambia el valor del dato.
    void cambiar_dato(T nuevo_dato);

    // POST: Devuelve un puntero al siguiente Nodo.
    Nodo<T>* obtener_siguiente();

    // POST: Cambia el siguiente Nodo por nuevo_siguiente.
    void cambiar_siguiente(Nodo<T>* nuevo_siguiente);

    // PRE:  La prioridad nueva deberia ser mayor o igual a cero
    // POST: Asigna un nuevo valor a la prioridad.
    void cambiar_prioridad(unsigned int prioridad_nueva);

    // POST: Devuelve la prioridad del nodo.
    unsigned int obtener_prioridad();
    ~Nodo();
};



template <class T>
Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = NULL;
    this->prioridad = 0;
}

template <class T>
Nodo<T>::Nodo(T dato, unsigned int prioridad) {
    this->dato = dato;
    this->siguiente = NULL;
    this->prioridad = prioridad;
}



template <class T>
T Nodo<T>::obtener_dato() {
    return this->dato;
}


template <class T>
void Nodo<T>::cambiar_dato(T nuevo_dato) {
    this->dato = nuevo_dato;
}

template <class T>
Nodo<T>* Nodo<T>::obtener_siguiente() {
    return this->siguiente;
}

template <class T>
void Nodo<T>::cambiar_siguiente(Nodo<T>* nuevo_siguiente) {
    this->siguiente = nuevo_siguiente;
}

template <class T>
void Nodo<T>::cambiar_prioridad(unsigned int prioridad_nueva) {
    this->prioridad = prioridad_nueva;
}

template <class T>
unsigned int Nodo<T>::obtener_prioridad() {
    return this->prioridad;
}


template<class T>
Nodo<T>::~Nodo(){
}
#endif
