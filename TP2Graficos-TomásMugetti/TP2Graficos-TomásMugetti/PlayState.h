#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>

class PlayState
{
	sf::RenderWindow *window;
public:
	PlayState(sf::RenderWindow &_window, bool &_init);
	void Start();
	void Movement(sf::Sprite &player1, sf::Sprite &player2, float tiempo, sf::Vector2u tam);
	void OOB(sf::Sprite &caja, sf::Vector2u tam);
	~PlayState();
};
#endif

