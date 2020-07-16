#ifndef CARTAS_H
#define CARTAS_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


class cartas
{
    public:
        cartas(Vector2f posicion);
 //       virtual ~cartas();
        Sprite get_sprite();
        int getNumero_cartas();
        int getCostoCartaMana();

    protected:

    private:
    Sprite cartasS;
    Texture cartasT;
    int numero_cartas;
    int CostoCartaMana;
};

#endif // CARTAS_H
