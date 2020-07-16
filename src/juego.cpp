#include "juego.h"
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

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

    event = new Event;

     bandera1= false;

     musicaIntro.openFromFile("musica/Inicio.ogg");

     musicaIntro.setVolume(20.f);

     reloj1 = new Clock();

     tiempo1 = new Time();

     reloj2= new Clock();

     tiempo3 = new Time();

     musica();

    for(int r=0;r<4;r++){

      slot_cartas[r] = false;
   }

 fuente1 = new Font();

 fuente1->loadFromFile("fuente/letra1.ttf");

  fuente2 = new Font();

 fuente2->loadFromFile("fuente/letra2.ttf");

    texto_MenuPrincipal = new Text();

    texto_MenuPrincipal -> setFont(*fuente2);

    texto_MenuPrincipal -> setPosition(200,550);

    texto_MenuPrincipal -> setString("PRESS SPACE TO CONTINUE");

    texto_vida =new Text();

    texto_vida->setFont(*fuente1);

    texto_vida->setPosition(50,30);

    texto_vida->setColor(Color::Red);

    texto_mana = new Text();

    texto_mana->setFont(*fuente1);

    texto_mana->setPosition(80,90);

    texto_mana->setColor(Color::Magenta);

    texto_escudo = new Text();

    texto_escudo->setFont(*fuente1);

    texto_escudo->setPosition(80,150);

    texto_escudo->setColor(Color::Black);

    texto_turno =new Text();

    texto_turno->setFont(*fuente2);

    texto_turno->setPosition(280,33);

    texto_turno->setColor(Color::White);

    texto_turno->setString("TERMINAR TURNO");

    texto_vidaEnemigo = new Text();

    texto_vidaEnemigo->setFont(*fuente1);

    texto_vidaEnemigo->setPosition(600,30);

    texto_vidaEnemigo->setColor(Color::Red);

    personajePri = new personaje;

    botonTurno = new RectangleShape({300,110});

    tex_botonTurno = new Texture;

    tex_botonTurno->loadFromFile("img/Boton.png");

    botonTurno->setTexture(tex_botonTurno);

    botonTurno->setPosition(250,00);

    turnoTerminado = false;

    enemigo1 = new enemigo;

    numeroCarta = 0 ;

    vida = personajePri->get_vida();

    mana = personajePri->get_mana();

    vidaEnemigo = enemigo1->get_vida();

    vidaActual = vida;

    vidaEnemigoActual = vidaEnemigo;

    vidaActualizando = 0;

    manaActualizando = 0;

    vidaEnemigoActualizando = 0;

    manaActual = mana;

    tiempo2 =0;

    tiempo4 =0;

    turnoTerminado = false;

    bandera2 = true;

 gameLoop();

}


void juego::dibujar()
{

     window->draw(*menuprincipalS);

        tiempo2 = tiempo1->asSeconds();

                    window->draw(*texto_MenuPrincipal);
        if(tiempo2>1.)
        {
            texto_MenuPrincipal->setColor(Color::Transparent);
            if(tiempo2>2.)
            {
                       texto_MenuPrincipal->setColor(Color::White);
             tiempo2=0;
             reloj1->restart();

            }

        }
     if(bandera1){
     window->draw(*EscenarioS);
     window->draw(personajePri->get_spritePersonaje());
     window->draw(enemigo1->get_spriteEnemigo());
         for(int i=0;i<4;i++)
    {
     if(cartas_tocadas[i]!=NULL)
                    {
    window->draw(cartas_tocadas[i]->get_sprite());
                    }
    }

    std::ostringstream ss;
        ss << vidaActual;
  string  s = ss.str();

  //  texto_vida->setString(to_string(vidaActual)+" HP");
    texto_vida->setString((s)+" HP");

        std::ostringstream mm;
        if(turnoTerminado) {manaActual=mana;}
        mm << manaActual;
  string  m = mm.str();

        texto_mana->setString(m);

        std::ostringstream ee;
        ee << vidaEnemigoActual;
  string  e = ee.str();

        texto_vidaEnemigo->setString((e)+" HP");

    window->draw(*texto_vida);

    window->draw(*texto_mana);

    window->draw(*texto_vidaEnemigo);

 //   if(!turnoTerminado){
    window->draw(*botonTurno);

    window->draw(*texto_turno);
   //                   }


    window->draw(personajePri->get_spriteMana());
                };


}


void juego::gameLoop(){

 while (window->isOpen())
    {

  //    if(tiempo1->asSeconds()<1/fps)
        window->clear();
        procesar_mouse();
        procesar_eventos();
        dibujar();
        *tiempo1 = reloj1->getElapsedTime();

    if(turnoTerminado==true||bandera2==true)
{
    turnoTerminado=false;
    bandera2=false;
//      *tiempo3 = reloj2->getElapsedTime();
//      tiempo4 = tiempo3->asSeconds();
//     if(tiempo4>1)
  {
    for(int i=0;i<4;i++)
    {
        if(!slot_cartas[i]){
            slot_cartas[i]=true;

  cartas_tocadas[i] = new cartas({ (float)(60+(150.0*i)),(float)430.0 });
            }
    }
// reloj2->restart();
  }
}

   window->display();
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
                            bandera1=true;
                        }
                    };
                break;

                    case Event::MouseButtonPressed:
                    {

    FloatRect mouse_seleccionador(Vector2f(posicion_mouse),{2.0,2.0});



    if (Mouse::isButtonPressed(Mouse::Left)&&bandera1)
                        {

                if(botonTurno->getGlobalBounds().intersects(mouse_seleccionador))
                {
                    turnoTerminado = true;

                }

                manaAlcanza = false;

                for(int i=0;i<4;i++){
                        if(cartas_tocadas[i]){

                          if (cartas_tocadas[i]->get_sprite().getGlobalBounds().intersects(mouse_seleccionador))
                          {

                                    numeroCarta = cartas_tocadas[i]->getNumero_cartas();
                                    int costoCartaMana = cartas_tocadas[i]->getCostoCartaMana();
                                    comprobarMana(costoCartaMana);
                                    if(manaAlcanza)
                                   {
                                    slot_cartas[i]=false;
                                    accion(numeroCarta);
                                    cartas_tocadas[i]=NULL;
                                   }


                          }
                                            }
                                    }



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

void juego::musica(){
if(bandera1==false){
  musicaIntro.play();
};
}

void juego::accion(int numeroCarta)
{
   if(numeroCarta == 0) ;

else if(numeroCarta == 1)
{
    vidaEnemigoActualizando=-15;
    vidaEnemigoActual = vidaEnemigoActual + vidaEnemigoActualizando;
}
else if(numeroCarta == 2|| numeroCarta == 5)
{
    vidaActualizando=30;
    vidaActual = vidaActual + vidaActualizando;
}
else if(numeroCarta == 3) ;
else if(numeroCarta == 4)
{
    vidaEnemigoActualizando=-20;
    vidaEnemigoActual = vidaEnemigoActual + vidaEnemigoActualizando;
}
else if(numeroCarta == 6) ;
else if(numeroCarta == 7)
{
    vidaEnemigoActualizando=-45;
    vidaEnemigoActual = vidaEnemigoActual + vidaEnemigoActualizando;
}
else if(numeroCarta == 8)
{
    vidaActualizando=5;
    vidaActual = vidaActual + vidaActualizando;
}
else if(numeroCarta == 9) ;
else if(numeroCarta == 10);
else if(numeroCarta == 11);
else if(numeroCarta == 12)
{

}

}

void juego::comprobarMana(int costoCartaMana)
{
    if(costoCartaMana<=manaActual)
    {
        manaAlcanza=true;
        manaActualizando=-(costoCartaMana);
        manaActual = manaActual+manaActualizando;
        }
}

//juego::~juego()
//{
    //dtor
//}
