#ifndef CARTAS_H
#define CARTAS_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


class cartas
{
    public:
        cartas();
 //       virtual ~cartas();
        Sprite get_sprite();

    protected:
 Sprite cartasS;
 Texture cartasT;
    private:
    int numero_cartas;
};

#endif // CARTAS_H
