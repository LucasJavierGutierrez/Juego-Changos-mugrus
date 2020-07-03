#include "cartas.h"
#include <cstdlib>
using namespace std;
using namespace sf;

cartas::cartas()
{
numero_cartas = rand() % 13 + 0 ;

std::string direccion;

        string s;
        /// NO PUDE PASARLO CON TO_STRING
if(numero_cartas == 0) s="";
else if(numero_cartas == 1) s="1";
else if(numero_cartas == 2) s="2";
else if(numero_cartas == 3) s="3";
else if(numero_cartas == 4) s="4";
else if(numero_cartas == 5) s="5";
else if(numero_cartas == 6) s="6";
else if(numero_cartas == 7) s="7";
else if(numero_cartas == 8) s="8";
else if(numero_cartas == 9) s="9";
else if(numero_cartas == 10) s="10";
else if(numero_cartas == 11) s="11";
else if(numero_cartas == 12) s="12";

//cartasT = new Texture;

//cartasS = new Sprite;

direccion = "img/Carta" + s + ".png";
  cartasT.loadFromFile(direccion);
  cartasS.setTexture(cartasT);
 // cartasS.setOrigin(400,300);
 // cartasS.setPosition(300,500);
  cartasS.setScale(266.0 /cartasT.getSize().x , 200.0 /cartasT.getSize().y);
}



Sprite cartas::get_sprite()
{

        return cartasS;
}

//cartas::~cartas()
//{
    //dtor
//}
