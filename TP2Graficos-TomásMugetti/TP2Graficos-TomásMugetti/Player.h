#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Constantes.h"

class Player
{
	bool movY;
	bool vivo;
	bool orden;
	bool intro;
	bool *start;
	bool *stop;
	bool frame; //true = frame 1, false = frame 2

	float contFrame;

	sf::RenderWindow *window;
	sf::Texture textura;
	sf::Clock clock;
	sf::Sprite nave;

public:
	Player(sf::RenderWindow &_window, float X, float Y, bool &_start, bool &_stop);
	void Update(float elapsed);
	~Player();

private:
	void Movimiento(bool direc, float tiempo);
	void OOB(sf::Vector2u tam);
	void animar(float elapsed);
};
#endif // !PLAYER_H

