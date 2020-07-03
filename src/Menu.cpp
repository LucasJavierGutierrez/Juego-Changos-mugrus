#include "Menu.h"

Menu::Menu()
{
     window = new RenderWindow(VideoMode(800, 600), "Mi primer juego");

     menuPrincipalT  = new Texture;

     menuprincipalS = new Sprite ;


     menuPrincipalT->loadFromFile("img/Menu_Principal.png");

     menuprincipalS->setTexture(*menuPrincipalT);


 gameLoop();

}

void Menu::dibujar()
{
     window->clear();
     window->draw(*menuprincipalS);
    window->display();

}

void Menu::gameLoop(){

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
        Event event1;

    if (Keyboard::isKeyPressed(Keyboard::Space))
    {

        return;
    }



     dibujar();




    }

}

Menu::~Menu()
{
    //dtor
}
