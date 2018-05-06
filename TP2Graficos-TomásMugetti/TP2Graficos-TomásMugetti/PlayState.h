#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Fondo.h"

class PlayState
{
	sf::RenderWindow *window;
	bool start;
	bool stop;
public:
	PlayState(sf::RenderWindow &_window);
	~PlayState();
	void Play();
};
#endif

