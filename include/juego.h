#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "cartas.h"
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

    protected:

    private:
    RenderWindow *window;
    int fps;
    Texture *menuPrincipalT;
    Sprite *menuprincipalS;
    Texture *Escenario;
    Sprite *EscenarioS;
    Texture *PersonajePri;
    Sprite *PersonajePriS;
    Vector2i posicion_mouse;
    Event *event;
    bool slot_cartas[4];
    cartas *cartas_tocadas[4];


};


#endif // JUEGO_H
