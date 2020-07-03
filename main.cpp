#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "juego.h"



using namespace std;
using namespace sf;

int main(int argc, char * args[])
{


srand(time(NULL));

juego *ventana1;

  ventana1 = new juego();


     return 0;
 /*

     Texture MenuPrincipal;
     Texture Escenario;
     Texture Fallen_angel1;

    if (!MenuPrincipal.loadFromFile("img/Menu_Principal.png"))
        return EXIT_FAILURE;
     Sprite Menu_principal(MenuPrincipal);

    if (!Fallen_angel1.loadFromFile("img/0_Fallen_Angels_Running_000.png"))
        return EXIT_FAILURE;
       Sprite sprite2(Fallen_angel1);
    sprite2.setOrigin(450,450);
    sprite2.setPosition(400,300);
    sprite2.setScale(Vector2f(0.2f, 0.2f));

  if (!Escenario.loadFromFile("img/nivel1.png"))
       return EXIT_FAILURE;


    // Create a graphical text to display
 /*   Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    Text text("LALALALALA PONY", font, 50);

    // Load a music to play
    Music music;
if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
   music.play();

*/
}
