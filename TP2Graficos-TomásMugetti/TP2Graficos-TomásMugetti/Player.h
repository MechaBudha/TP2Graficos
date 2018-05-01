#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
class Player
{
	bool movY;
	bool vivo;
	bool orden;
	sf::RenderWindow *window;
	sf::Texture textura;
	sf::Clock clock;
	sf::Sprite nave;

public:
	Player(sf::RenderWindow &_window, float X, float Y);
	void Update(float elapsed);
	~Player();

private:
	void Movimiento(bool direc, float tiempo);
	void OOB(sf::Vector2u tam);
};
#endif // !PLAYER_H

