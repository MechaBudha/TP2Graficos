#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "PlayState.h"
#include "Constantes.h"

void main(){
	sf::RenderWindow window(sf::VideoMode(Constantes::ANCHOPANTALLA, Constantes::ALTOPANTALLA), "Juego");
	PlayState play(window);
	play.Play();
}