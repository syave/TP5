#ifndef GRAFOS_AEROPUERTO_H
#define GRAFOS_AEROPUERTO_H

#include <string>
using namespace std;

class Aeropuerto {
private:
    string codigo;
public:
    Aeropuerto();
    ~Aeropuerto();

    string get_codigo();
    void set_codigo(string codigo);
};


#endif //GRAFOS_AEROPUERTO_H
