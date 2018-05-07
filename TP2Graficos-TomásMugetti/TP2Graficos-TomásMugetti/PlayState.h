#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Fondo.h"
#include "ControlMeteoro.h"

class PlayState
{
	sf::RenderWindow *window;
	bool start;
	bool stop;
	bool *win;
public:
	PlayState(sf::RenderWindow &_window, bool &_win);
	~PlayState();
	void Play();
};
#endif

