#include "Grafo.h"
const int NO_HAY_CAMINO = 999999;

using namespace std;

Grafo::Grafo() {
    this->vertices = new Lista<Vertice*>();
    this->tam = 0;
}

Lista<Vertice*>* Grafo::obtener_vertices() {
    return this->vertices;
}

unsigned Grafo::obtener_tam() {
    return this->tam;
}


void Grafo::insertar_nodo(string elemento){
    this->insertar_nodo(elemento,this->tam+1);
}

void Grafo::insertar_nodo(string elemento, unsigned int indice) {
    if (this->existe_nodo(elemento) == NULL) {
        unsigned int nuevo_indice = indice;
        if (indice == 0)
            nuevo_indice = this->tam + 1;
        Vertice* nuevo_vertice = new Vertice(elemento, nuevo_indice);
        this->vertices->agregar(nuevo_vertice);
        this->tam++;
    }
}

Vertice* Grafo::existe_nodo(string elemento) {
    Vertice* vertice = NULL;
    bool encontrado = false;
    this->vertices->iniciar_cursor();
    while (this->vertices->avanzar_cursor() && !encontrado) {
        encontrado = elementos_son_iguales(this->vertices->obtener_cursor()->obtener_elemento(), elemento);
        if (encontrado) {
            vertice = vertices->obtener_cursor();
        }
    }
    return vertice;
}

bool Grafo::elementos_son_iguales(string primer_elemento, string segundo_elemento) {
    return primer_elemento == segundo_elemento;

}

void Grafo::insertar_arista(string elemento_origen, string elemento_destino, float peso, float tiempo) {
    Vertice* origen = this->existe_nodo(elemento_origen);
    Vertice* destino = this->existe_nodo(elemento_destino);

    if (origen != NULL && destino != NULL) {
        Arista* nueva_arista = new Arista(destino, peso, tiempo);
        origen->agregar_arista(nueva_arista);
    }
}

void Grafo::insertar_arista(unsigned int indice_vertice_origen, unsigned int indice_vertice_destino, unsigned peso, unsigned tiempo) {
    Vertice* origen = this->obtener_vertice_por_indice(indice_vertice_origen);
    Vertice* destino = this->obtener_vertice_por_indice(indice_vertice_destino);

    if (origen != NULL && destino != NULL) {
        Arista* nueva_arista = new Arista(destino, peso, tiempo);
        origen->agregar_arista(nueva_arista);
    }
}

void Grafo::eliminar_nodo(Vertice* eliminar) {
    if (eliminar != NULL) {
        delete eliminar->obtener_adyacentes();
        this->vertices->remover(eliminar);
    }
}

Vertice* Grafo::obtener_vertice_por_indice(unsigned int indice) {
    Vertice* actual;
    this->vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        actual = this->vertices->obtener_cursor();
        if (actual->obtener_indice() == indice)
            return actual;
    }
    return NULL;
}

Vertice* Grafo::obtener_vertice_por_elemento(string elemento) {
    Vertice* actual;
    this->vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        actual = this->vertices->obtener_cursor();
        if (actual->obtener_elemento() == elemento)
            return actual;
    }
    return NULL;
}



Grafo::~Grafo() {
    this->vertices->iniciar_cursor();
    while (vertices->avanzar_cursor()) {
        delete this->vertices->obtener_cursor();
    }
    delete vertices;
}

void Grafo::obtener_camino_minimo(Vertice *origen, Vertice *destino, unsigned opcion) {
    if (origen != NULL && destino != NULL) {
        int* padre = this->inicializar_vector_rutas();
        unsigned* costos = this->inicializar_vector(origen,opcion);
        ColaPrioridad<Vertice*>* cola = this->inicializar_cola(origen, costos);
        while (!cola->esta_vacia()) {
            Vertice* actual = cola->desacolar();
            if (actual != NULL) {
                Lista<Arista*>* adyacentes = actual->obtener_adyacentes();
                adyacentes->iniciar_cursor();
                while (adyacentes->avanzar_cursor()) {
                    Arista* analizada = adyacentes->obtener_cursor();
                    if (analizada != NULL) {
                        float temporal;
                        if (opcion==1){
                            temporal = costos[actual->obtener_indice()] + analizada->obtener_peso();
                        }
                        else{
                            temporal = costos[actual->obtener_indice()] + analizada->obtener_tiempo();
                        }
                        Vertice* actualiza = analizada->obtener_destino();
                        if (actualiza != NULL) {
                            unsigned int actualiza_indice = actualiza->obtener_indice();
                            if (costos[actualiza_indice] > temporal) {
                                costos[actualiza_indice] = temporal;
                                cola->actualizar_valor(actualiza, temporal);         // Esto solo devuelve el menor peso total.
                                padre[actualiza_indice] = actual->obtener_indice(); // Esto devuelve la ruta detallada.
                            }
                        }
                    }
                }
            }
        }
        //imprimir_todos_los_caminos(costos, padre); //todos los caminos hacia todos los destinos
        imprimir_camino_total(costos,destino->obtener_indice(),padre,opcion); //camino minimo hacia destino
        delete[] costos;
        delete[] padre;
        delete cola;
    }
}

void Grafo::construir_camino(int padre[], int indice, Lista<Vertice*>* &vertices) {
    if (padre[indice] == - 1)
        return;
    construir_camino(padre, padre[indice], vertices);
    vertices->agregar(this->obtener_vertice_por_indice(indice));
}

void Grafo::imprimir_camino(int padre[], int indice) {
    // Caso Base: si indice es origen
    if (padre[indice] == - 1){
        return;
    }
    imprimir_camino(padre, padre[indice]);
    cout << obtener_vertice_por_indice(indice)->obtener_elemento()<< "->";
}

void Grafo::imprimir_todos_los_caminos(unsigned* dist, int padre[]) {
    cout << "Aeropuerto\t\t Distancia\t\t\tCamino" << endl;

    for (unsigned int i = 1; i <= obtener_tam(); i++) {
        if(dist[i] == 0 || dist[i] == NO_HAY_CAMINO) {
            cout << obtener_vertices()->obtener(i)->obtener_elemento();
            cout << " \t\t" << "NO HAY CAMINO" << " \t\t" << " [NO HAY CAMINO] "<<endl;
        }else{
            cout << obtener_vertices()->obtener(i)->obtener_elemento();
            cout << " \t\t\t " << dist[i] << "\t\t\t\t" << " [ ";
            imprimir_camino(padre, i);
            cout << " ]" << endl;
        }
    }
}

void Grafo::imprimir_camino_total(unsigned* dist, int indice, int padre[], unsigned opcion) {
    if (padre[indice] == - 1){
        return;
    }
    cout << "Camino Minimo: "<<endl;
    imprimir_camino(padre, padre[indice]);
    if(dist[indice] == 0 || dist[indice] == NO_HAY_CAMINO) {
        cout<< "NO HAY CAMINO"<<endl;
    }else{
        cout << obtener_vertice_por_indice(indice)->obtener_elemento() << "->"<<endl;
        if (opcion==1){
            cout << "Costo($): " << dist[indice] << endl;
        }
        else{
            cout << "Tiempo(minutos): " << dist[indice]/60<<" Horas - " <<dist[indice]%60 <<" minutos"<<endl;
        }
    }
}

int* Grafo::inicializar_vector_rutas() {
    // Vector 'Padre' para almacenar detalladamente el camino mas corto.
    int* padre = new int[this->obtener_tam()];
    padre[0] = -1;
    for (unsigned int i = 1; i <= tam; i++) {
        padre[i] = 0;
    }
    return padre;
}

unsigned* Grafo::inicializar_vector(Vertice* origen, unsigned opcion) {
    unsigned* costos = new unsigned[this->obtener_tam()];
    for (unsigned i = 0; i < this->obtener_tam(); i++) {
        costos[i] = NO_HAY_CAMINO;
    }
    if (origen != NULL) {
        Lista<Arista*>* adyacentes = origen->obtener_adyacentes();
        adyacentes->iniciar_cursor();
        while (adyacentes->avanzar_cursor()) {
            Arista* analizada = adyacentes->obtener_cursor();
            if (analizada != NULL) {
                Vertice* analizada_destino = analizada->obtener_destino();
                if (analizada_destino != NULL) {
                    unsigned analizada_peso;
                    if (opcion==1) {
                        analizada_peso = analizada->obtener_peso();
                    }
                    else{
                        analizada_peso = analizada->obtener_tiempo();
                    }
                    unsigned analizada_destino_indice = analizada_destino->obtener_indice();
                    costos[analizada_destino_indice] = analizada_peso;
                }
            }
        }
        costos[origen->obtener_indice()] = 0;
    }
    return costos;
}

ColaPrioridad<Vertice*>* Grafo::inicializar_cola(Vertice* origen, unsigned* costos) {
    ColaPrioridad<Vertice*>* cola = new ColaPrioridad<Vertice*>();
    this->vertices->iniciar_cursor();
    while (this->vertices->avanzar_cursor()) {
        Vertice* actual = this->vertices->obtener_cursor();
        if (actual != NULL && origen != NULL) {
            if (actual->obtener_indice() != origen->obtener_indice()) {
                cola->acolar(actual, costos[actual->obtener_indice()]);
            }
        }
    }
    return cola;
}
