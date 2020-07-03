#ifndef MENU_H
#define MENU_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
    public:
        Menu();
        void dibujar();
        void gameLoop();
        virtual ~Menu();

    protected:

    private:
    RenderWindow *window;
    Texture *menuPrincipalT;
    Sprite *menuprincipalS;
};


#endif // MENU_H
