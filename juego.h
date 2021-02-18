#ifndef TP_3_JUEGO_H
#define TP_3_JUEGO_H

#include "jugador.h"

class Juego {

    // atributos
private:
    Jugador jugador1, jugador2;
    Grafo tablero;

    // metodos
public:
    // PRE:
    // POS:
    void iniciar();

    // PRE:
    // POS:
    Jugador obtenerJugador1();

    // PRE:
    // POS:
    Jugador obtenerJugador2();

private:
    // PRE: -
    // POS: detiene la ejecucion del programa hasta que el usuario presione una tecla para continuar
    void pausar();

    // PRE: -
    // POS: borra el contenido previo mostrado por pantalla
    void limpiarPantalla();

    // PRE:
    // POS:
    void posicionarPersonajes();

    // PRE:
    // POS:
    void cicloPrincipal();

    // PRE:
    // POS:
    bool terminado();

    // PRE:
    // POS:
    void mostrarGanador();
};


#endif //TP_3_JUEGO_H
