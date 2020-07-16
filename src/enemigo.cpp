#include "enemigo.h"

enemigo::enemigo()
{
    EnemigoT = new Texture;

    EnemigoS = new Sprite;

    EnemigoT-> loadFromFile("img/Enemigo1.png");

    EnemigoS->setTexture(*EnemigoT);

 //   EnemigoS->setScale(266.0 /EnemigoT->getSize().x , 200.0 /EnemigoT->getSize().y);

    EnemigoS->setPosition(600,300);

    vida = 500;

}

Sprite enemigo::get_spriteEnemigo()
{
    return *EnemigoS;
}

int enemigo::get_vida()
{
    return vida;
}


enemigo::~enemigo()
{
    //dtor
}
