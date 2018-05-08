#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Constantes.h"
#include "Trazo.h"

class Player
{
	bool vivo;
	bool intro;
	bool *start;
	bool *stop;
	bool frame; //true = frame 1, false = frame 2
	int velX;
	int velY;

	float contFrame;

	sf::RenderWindow *window;
	sf::Texture textura;
	sf::Clock clock;
	sf::Sprite nave;
	sf::Sprite *cola;

public:
	Player(sf::RenderWindow &_window, float X, float Y, bool &_start, bool &_stop);
	void Update(float elapsed);
	~Player();

private:
	void Movimiento(float tiempo);
	void OOB(sf::Vector2u tam);
	sf::FloatRect Pos();
	void animar(float elapsed);
};
#endif // !PLAYER_H

