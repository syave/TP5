#ifndef NODO_H_
#define NODO_H_

template <class T> class Nodo {
  public:

    // PRE: 
    // POST: 
    Nodo(T dato) {
      this->dato = dato;
      this->siguiente = NULL;
      this->prioridad = 0;
    }

    // PRE: 
    // POST: 
    Nodo(T dato, unsigned int prioridad) {
        this->dato = dato;
        this->siguiente = NULL;
        this->prioridad = prioridad;
    }

    // PRE: 
    // POST: 
    T obtener_dato() {
      return this->dato;
    }

    // PRE: 
    // POST: 
    void cambiar_dato(T nuevo_dato) {
      this->dato = nuevo_dato;
    }

    // PRE: 
    // POST: 
    Nodo<T>* obtener_siguiente() {
      return this->siguiente;
    }

    // PRE: 
    // POST: 
    void cambiar_siguiente(Nodo<T>* nuevo_siguiente) {
      this->siguiente = nuevo_siguiente;
    }

    // PRE: 
    // POST: 
    void cambiar_prioridad(unsigned int prioridad_nueva) {
        this->prioridad = prioridad_nueva;
    }

    // PRE: 
    // POST: 
    unsigned int obtener_prioridad() {
        return this->prioridad;
    }

  private:
  T dato;
  Nodo<T>* siguiente;
  unsigned int prioridad;

};

#endif
