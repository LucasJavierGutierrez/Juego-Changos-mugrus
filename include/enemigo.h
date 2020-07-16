#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class enemigo
{
    public:
        enemigo();
        Sprite get_spriteEnemigo();
        int get_vida();

        virtual ~enemigo();

    protected:


    private:

    int vida;
    Texture *EnemigoT;
    Sprite *EnemigoS;

};

#endif // ENEMIGO_H
