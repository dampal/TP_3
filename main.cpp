#include "archivoTablero.h"
#include "archivoPartida.h"
#include "archivoPersonajes.h"
#include "menuPrincipal.h"


int main() {

    ArchivoTablero archivoTablero;
    ArchivoPartida archivoPartida;
    ArchivoPersonajes archivoPersonajes;
    DiccionarioABB<string, Personaje*> diccionario;
    MenuPrincipal menuPrincipal;
    Juego juego;

    menuPrincipal.iniciar();

    if (archivoTablero.estaAbierto()) {

        archivoTablero.cargarTablero(juego.obtenerTablero());

        if (archivoPartida.hayPartidaGuardada()) {

            cout << "\n Cargando partida guardada.." << endl;
            menuPrincipal.pausar();

            archivoPartida.cargarPartida(juego);
            juego.reanudarPartida();

        }

        else {          // empieza una nueva partida

            if (archivoPersonajes.estaAbierto()) {

                archivoPersonajes.procesarArchivo(diccionario);
                cout << "\n El archivo de personajes se ha cargado correctamente" << endl;
            }
            else
                cout << "\n Error al abrir el archivo de personajes" << endl;

            menuPrincipal.pausar();

            menuPrincipal.interfazPrincipal(juego, diccionario);

        }

    }

    else                                                            // sin el archivo del tablero no se puede jugar
        cout << "\n Error al abrir el archivo del tablero" << endl;


    return 0;
}
