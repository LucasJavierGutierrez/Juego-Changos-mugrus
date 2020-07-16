#include "cartas.h"
#include <cstdlib>
using namespace std;
using namespace sf;

cartas::cartas(Vector2f posicion)
{


numero_cartas = rand() % 13 + 0 ;

std::string direccion;

        string s;


        /// NO PUDE PASARLO CON TO_STRING
if(numero_cartas == 0){s="";CostoCartaMana =3;}
else if(numero_cartas == 1) {s="1"; CostoCartaMana =1;}
else if(numero_cartas == 2) {s="2"; CostoCartaMana =1;}
else if(numero_cartas == 3) {s="3"; CostoCartaMana = 3;}
else if(numero_cartas == 4) {s="4"; CostoCartaMana =3 ;}
else if(numero_cartas == 5) {s="2"; CostoCartaMana =1 ;}
else if(numero_cartas == 6) {s="6"; CostoCartaMana = 3;}
else if(numero_cartas == 7) {s="7"; CostoCartaMana = 5;}
else if(numero_cartas == 8) {s="8"; CostoCartaMana = 4;}
else if(numero_cartas == 9) {s="9"; CostoCartaMana = 2;}
else if(numero_cartas == 10) {s="10"; CostoCartaMana = 2;}
else if(numero_cartas == 11) {s="11"; CostoCartaMana = 2;}
else if(numero_cartas == 12) {s="12"; CostoCartaMana = 2;}


direccion = "img/Carta" + s + ".png";

  cartasT.loadFromFile(direccion);

  cartasS.setTexture(cartasT);

  cartasS.setScale(266.0 /cartasT.getSize().x , 200.0 /cartasT.getSize().y);

  cartasS.setPosition(posicion);

}


int cartas::getNumero_cartas()
{
    return numero_cartas;
}

int cartas::getCostoCartaMana()
{
    return CostoCartaMana;
}

Sprite cartas::get_sprite()
{

        return cartasS;
}

//cartas::~cartas()
//{
    //dtor
//}
