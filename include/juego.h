#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


class juego
{
    public:
        juego();
       // virtual ~juego();

        void dibujar();
        void gameLoop();
    protected:

    private:
    RenderWindow *window;
    int fps;
    Texture menuPrincipalT;
    Sprite menuprincipalS;
    Texture *Escenario;
};

#endif // JUEGO_H
