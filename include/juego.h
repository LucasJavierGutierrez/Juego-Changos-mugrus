#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> // LA AGREGUE PARA  VER UN PAR DE  COSAS POR  CONSOLA
#include "cartas.h"
#include "personaje.h"
#include "enemigo.h"

using namespace sf;


class juego
{
    public:
        juego();
       // virtual ~juego();

        void dibujar();
        void gameLoop();
        void procesar_mouse();
        void procesar_eventos();
        void musica();
        void accion(int numeroCarta);
        void comprobarMana(int costoCartaMana);

    protected:

    private:
    RenderWindow *window;
    int fps;
    Texture *menuPrincipalT;
    Sprite *menuprincipalS;
    Texture *Escenario;
    Sprite *EscenarioS;
    Vector2i posicion_mouse;
    Event *event;
    bool  slot_cartas[4];
    cartas *cartas_tocadas[4];
    personaje *personajePri;
    bool  bandera1;
    bool bandera2;
    Music musicaIntro;
    Clock *reloj1;
    Clock *reloj2;
    Time *tiempo1;
    Time *tiempo3;
    Font *fuente1;
    Font *fuente2;
    Text *texto_MenuPrincipal;
    Text *texto_vida;
    Text *texto_mana;
    Text *texto_escudo;
    Text *texto_turno;
    Text *texto_vidaEnemigo;
    bool turnoTerminado;
    int contadorTurnos;
    RectangleShape *botonTurno;
    Texture *tex_botonTurno;
    enemigo *enemigo1;
    int numeroCarta;
    int vidaActual;
    int manaActual;
    int vidaEnemigoActual;
    int vidaActualizando;
    int manaActualizando;
    int vidaEnemigoActualizando;
    int vida;
    int mana;
    int vidaEnemigo;
    bool manaAlcanza;
    float tiempo2;
    float tiempo4;
    int tt;

};


#endif // JUEGO_H
