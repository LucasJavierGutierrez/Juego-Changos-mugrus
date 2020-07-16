#include "personaje.h"

personaje::personaje()
{
    PersonajePri = new Texture;

    PersonajePriS = new Sprite;

    PersonajePri-> loadFromFile("img/PP1.png");

    PersonajePriS->setTexture(*PersonajePri);

    PersonajePriS->setOrigin(400,200);

    PersonajePriS->setPosition(200,400);

    tex_mana = new Texture;

    sprite_mana = new Sprite;

    tex_mana -> loadFromFile("img/mana.png");

    sprite_mana -> setTexture(*tex_mana);

    sprite_mana ->setPosition(140,80);

    vida = 140;

    mana = 1;

}

Sprite personaje::get_spritePersonaje()
{
    return *PersonajePriS;
}

int personaje::get_vida()
{
    return vida;
}

int personaje::get_mana()
{
    return mana;
}

Sprite personaje::get_spriteMana()
{
    return *sprite_mana;
}


personaje::~personaje()
{
    //dtor
}
