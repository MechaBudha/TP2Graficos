#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>

class PlayState
{
	sf::RenderWindow *window;
	bool start;
	bool stop;
public:
	PlayState(sf::RenderWindow &_window, bool &_init);
	~PlayState();
	void Play();
};
#endif

