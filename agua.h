#ifndef TP_3_AGUA_H
#define TP_3_AGUA_H

#include "personaje.h"

class Agua : public Personaje {

    // atributos
private:
    short int vecesAlimentado = 0;

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de agua con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Agua(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: devuelve COD_AGUA
    string obtenerElemento() override;

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: aumenta o no la energia segun el caso y muestra un mensaje por pantalla
    void alimentar() override;

    // PRE: el vector parametro contiene tres personajes
    // POS: de cumplirse los requisitos especificos de cada elemento, realiza el efecto de ataque correspondiente
    void atacar(array<Personaje*,3> enemigos) override;

    // PRE: el vector parametro contiene 3 personajes
    // POS: de cumplirse los requisitos de cada elemento, realiza el efecto de defensa correspondiente
    void defender(array<Personaje*,3> aliados) override;

    // PRE: -
    // POS: devuelve el daño que recibiria el personaje al ser atacado por el atacante,
    //      teniendo en cuenta elementos, escudo y habilidades especiales.
    int calcularAtkEntrante(Personaje* enemigo) override;

private:
    // PRE: el personaje no debe tener su energia al maximo y no haber alcanzado el limite de vecesAlimentado
    // POS: aumenta la cantidad de energia que corresponda, lo muestra por pantalla e incrementa vecesAlimentado en 1
    void aumentarEnergia() override;

    // PRE:
    // POS:
    void curarAliado(Personaje* aliado);

    // PRE:
    // POS:
    void mostrarMsjDefensa(int nuevaVidaPropia);

};


#endif //TP_3_AGUA_H
