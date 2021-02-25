#ifndef TP_3_CASILLERO_H
#define TP_3_CASILLERO_H

#include "personaje.h"

class Casillero {

    // atributos
private:
    Personaje* personaje = nullptr;

    // metodos
public:
    // PRE:
    // POS:
    void asignarPersonaje(Personaje* personaje);

    // PRE:
    // POS:
    bool estaVacio();

    // PRE:
    // POS:
    virtual int obtenerCosto(string elemento) = 0;

    // destructor
    // PRE: -
    // POS: libera el espacio de memoria que corresponda segun el tipo de casillero
    virtual ~Casillero() = default;

};


#endif //TP_3_CASILLERO_H
