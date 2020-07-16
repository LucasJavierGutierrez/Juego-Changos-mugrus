#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class personaje
{
    public:
        personaje();
        Sprite get_spritePersonaje();
        Sprite get_spriteMana();
        int get_vida();
        int get_mana();
        void set_mana(int m);
        virtual ~personaje();


    protected:

    private:
    int vida;
    int mana;
    Texture *PersonajePri;
    Sprite *PersonajePriS;
    Texture *tex_mana;
    Sprite *sprite_mana;
};

#endif // PERSONAJE_H
