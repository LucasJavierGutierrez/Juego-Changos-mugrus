#include "juego.h"
#include <cstdlib>
using namespace std;
using namespace sf;



juego::juego()
{
 window = new RenderWindow(VideoMode(800, 600), "Mi primer juego");

 fps=60;

 window->setFramerateLimit(fps);


menuPrincipalT  = new Texture;

 menuprincipalS = new Sprite ;


     menuPrincipalT->loadFromFile("img/Menu_Principal.png");

     menuprincipalS->setTexture(*menuPrincipalT);

Escenario = new Texture;

EscenarioS = new Sprite;

    Escenario->loadFromFile("img/nivel1s.png");

    EscenarioS->setTexture(*Escenario);

PersonajePri = new Texture;

PersonajePriS = new Sprite;

    PersonajePri-> loadFromFile("img/PP1.png");

    PersonajePriS->setTexture(*PersonajePri);

  PersonajePriS->setOrigin(400,200);

    PersonajePriS->setPosition(200,400);

    event = new Event;

    for(int r=0;r<4;r++){

        slot_cartas[r] = false;
///    slot_cartas[r].setOrigin(400,300);
    }


   /// slot_cartas[1].setPosition(300,500);

 ///   slot_cartas[2].setPosition(500,500);

  ///  slot_cartas[3].setPosition(700,500);

   /// slot_cartas[4].setPosition(900,500);



 gameLoop();

}


void juego::dibujar()
{

     window->draw(*menuprincipalS);
     window->draw(*EscenarioS);
     window->draw(*PersonajePriS);



}

void juego::gameLoop(){

 while (window->isOpen())
    {
        window->clear();
        procesar_mouse();
        procesar_eventos();

        dibujar();

    for(int i=0;i<4;i++)
    {
       if(cartas_tocadas!=NULL)
                    {
 ///   window->draw(cartas_tocadas[i]->get_sprite());
                    }
         }
   window->display();


/*      if (Keyboard::isKeyPressed(Keyboard::Space)){
            window.clear();
                    window.draw(sprite2);

                }
        // Clear screen
        window.clear();
        // Draw the sprite
     //   window.draw(sprite1);
        window.draw(Menu_principal);

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            /// PONER ACA LO Q VA A HACER
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
             ///PONER ACA LO Q VA A HACER


       // Draw the string
//        window.draw(text);
        // Update the window
*/




    }

}

void juego::procesar_eventos(){


    while (window->pollEvent(*event))
      {
            switch (event->type)
                {
                    case Event::Closed:
                    {

                        window->close();

                    };
                break;

                    case Event::KeyPressed:
                    {
    if (Keyboard::isKeyPressed(Keyboard::Space))
                        {

                        }
                    };
                break;

                    case Event::MouseButtonPressed:
                    {
    if (Mouse::isButtonPressed(Mouse::Left))
                        {
        //    if(posicion_mouse == (Vector2i)PersonajePriS->getPosition())
          //                      {
                                    PersonajePriS->setColor(Color::Red);
            //                    }
                        }


                    };
                break;

            }
      }
}


void juego::procesar_mouse(){

    posicion_mouse = Mouse::getPosition(*window);

    posicion_mouse = (Vector2i)window->mapPixelToCoords(posicion_mouse);

}



//juego::~juego()
//{
    //dtor
//}
