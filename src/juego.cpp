#include "juego.h"
#include <cstdlib>
using namespace std;
using namespace sf;



juego::juego()
{
 window = new RenderWindow(VideoMode(800, 600), "Mi primer juego");

 fps=60;

 window->setFramerateLimit(fps);

 gameLoop();

  Texture menuPrincipalT;

 Sprite menuprincipalS;


     menuPrincipalT.loadFromFile("img/Menu_Principal.png");

     menuprincipalS.setTexture(menuPrincipalT);

}

void juego::dibujar()
{
     window->clear();
     window->draw(menuprincipalS);
    window->display();

}

void juego::gameLoop(){

 while (window->isOpen())
    {
        // Process events
       Event event;
    while (window->pollEvent(event))
      {
           // Close window: exit
            if (event.type == Event::Closed){
            window->close();
                }

        }

     dibujar();

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


//juego::~juego()
//{
    //dtor
//}
