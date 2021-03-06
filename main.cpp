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
    Juego* juego = new Juego();

    menuPrincipal.iniciar();

    if (archivoTablero.estaAbierto()) {

        archivoTablero.cargarTablero(juego->obtenerTablero());

        cout << "\n\n El tablero se ha cargado correctamente \n\n" ;
        menuPrincipal.pausar();

        if (archivoPartida.hayPartidaGuardada()) {

            cout << "\n\n Cargando partida guardada..\n\n" ;
            menuPrincipal.pausar();

            archivoPartida.cargarPartida(juego);
            juego->reanudarPartida();

        }

        else {          // empieza una nueva partida

            if (archivoPersonajes.estaAbierto()) {

                cout << "\n\n Se procedera a cargar el archivo de personajes.. \n\n" ;
                menuPrincipal.pausar();

                archivoPersonajes.procesarArchivo(diccionario);
                cout << "\n\n El archivo de personajes se ha cargado correctamente \n\n" ;
            }
            else
                cout << "\n\n Error al abrir el archivo de personajes \n\n" ;

            menuPrincipal.pausar();

            menuPrincipal.interfazPrincipal(juego, diccionario);

        }

    }

    else                                                            // sin el archivo del tablero no se puede jugar
        cout << "\n Error al abrir el archivo del tablero \n\n" ;

    cout << "\n\n\n El programa ha finalizado \n\n" ;

    delete juego;

    return 0;

}
