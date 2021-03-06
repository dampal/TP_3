#include "agua.h"


string Agua::obtenerElemento() {

    return COD_AGUA;

}


bool Agua::defensaActivada() {

    return false;

}


void Agua::mostrar() {

    cout << "\n Elemento: Agua" << endl;

    mostrarAtributos();

}


void Agua::alimentar() {

    cout << "\n\n Elemento: Agua" ;

    if ( energiaMaxima() )

        cout << "\n\n El personaje tiene la maxima cantidad de energia (" << ENERGIA_MAXIMA << ") \n\n" ;

    else
        if (vecesAlimentado < CANT_MAX_PLANCTON)

            aumentarEnergia();

        else
            cout << "\n\n No hay mas plancton para '" << nombre << "', ya se ha alimentado 3 veces al personaje \n" << endl;


}


void Agua::atacar(Personaje** enemigos) {

    array<int,2> posEnemigo{}, input{};
    bool hayEnemigos = false;

    if (energia < ENERGIA_ATK_AGUA)

        cout << "\n\nLa energia actual es insuficiente para atacar. Valor requerido: " << ENERGIA_ATK_AGUA << endl;

    else {

        cout << "\nInserte las coordenadas a las que desea atacar." << endl;
        input = pedirCoordenadas();

        energia -= ENERGIA_ATK_AGUA;

        for (int i = 0; i < MAX_PERSONAJES; i++) {

            posEnemigo = enemigos[i]->obtenerPosicion();

            if (posEnemigo == input) {

                restarVida(enemigos[i]);
                hayEnemigos = true;
            }

        }

        if (!hayEnemigos)
            cout << "\n'" << this->obtenerNombre() <<"' ataca a la posicion indicada, pero no habia enemigos ahi." << endl;

    }

}


void Agua::defender(Personaje** aliados) {

    int nuevaVidaPropia;

    if (energia < ENERGIA_DEF_AGUA)

        cout << "\n\nLa energia actual es insuficiente para defender. Valor requerido: " << ENERGIA_DEF_AGUA << endl;

    else {

        energia -= ENERGIA_DEF_AGUA;

        if (vida + RECUP_DEF_AGUA > VIDA_MAXIMA)

            nuevaVidaPropia = VIDA_MAXIMA - vida;

        else
            nuevaVidaPropia = RECUP_DEF_AGUA;

        vida += nuevaVidaPropia;

        short int i = 0;

        while (aliados[i]) {

            if (aliados[i] != this)
                curarAliado(aliados[i]);

            i++;

        }

        mostrarMsjDefensa(nuevaVidaPropia);

    }

}


int Agua::calcularAtkEntrante(Personaje* enemigo) {

    int danio;
    string elemento = enemigo->obtenerElemento();

    if (elemento == COD_AGUA)

        danio = ATK_BASE_AGUA;

    else if (elemento == COD_AIRE)

        danio = ATK_BASE_AIRE;

    else if (elemento == COD_FUEGO)

        danio = ATK_BASE_FUEGO - MOD_ATK_FUEGO;

    else if (elemento == COD_TIERRA){

        danio = calcularAtkEntranteTierra(enemigo);
        danio += MOD_ATK_TIERRA;

    }

    return (int) ( danio - danio * (MOD_ESCUDO * escudo) );


}


void Agua::aumentarEnergia() {

    int nuevaEnergia;

    if (energia + ENERGIA_PLANCTON > ENERGIA_MAXIMA)

        nuevaEnergia = ENERGIA_MAXIMA - energia;

    else
        nuevaEnergia = ENERGIA_PLANCTON;

    energia += nuevaEnergia;

    vecesAlimentado ++;

    cout << "\n\n '" << nombre << "' se ha alimentado correctamente de plancton, suma " << nuevaEnergia << " punto/s de energia" << endl << endl
         << " Recuerde que el plancton es muy dificil de conseguir, por lo que solo se lo puede alimentar " << CANT_MAX_PLANCTON << " veces en total (queda/n " << CANT_MAX_PLANCTON - vecesAlimentado << ")" << endl;

    cout << "\n Energia anterior: " << energia - nuevaEnergia << " -----> Energia actual: " << energia << "\n\n";

}


void Agua::curarAliado(Personaje* aliado) {

    int nuevaVidaAliado;

    nuevaVidaAliado = aliado->obtenerVida();
    nuevaVidaAliado += CURA_DEF_AGUA;

    if (nuevaVidaAliado > VIDA_MAXIMA)

        aliado->asignarVida(VIDA_MAXIMA);

    else
        aliado->asignarVida(nuevaVidaAliado);

}


void Agua::mostrarMsjDefensa(int nuevaVidaPropia) {

    cout << "\n\n '" << nombre << "' ha convertido 12 puntos de energía en " << nuevaVidaPropia << " punto/s de vida" << endl;
    cout << "\n Ha curado " << CURA_DEF_AGUA << " puntos de vida a sus aliados. \n";
    cout << "\n Vida anterior: " << vida - nuevaVidaPropia << " -----> Vida actual: " << vida << "\n\n";
    cout << "\n Energia actual: " << energia;

}

