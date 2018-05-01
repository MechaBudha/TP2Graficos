#include "Player.h"
#include <iostream>
#define VEL 200


Player::Player(sf::RenderWindow &_window, float	X,float Y)
{
	window = &_window;
	movY = true;
	vivo = true;
	orden = true;

	if (!textura.loadFromFile("Assets/Img/Nave.png"))
	{
		std::cout << "Textura de player no carga" << std::endl;
	}
	textura.setRepeated(false);
	textura.setSmooth(true);
	nave.setTexture(textura);
	nave.setPosition(X,Y);
}

void Player::Update(float elapsed){
	if (vivo)
	{
		if (orden){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				movY = !movY; //true suma en y, false resta
				orden = false;
			}
		}else{
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){orden = true;}
		}
		
		OOB(window->getSize());
		Movimiento(movY, elapsed);
		window->draw(nave);
	}
}
void Player::Movimiento(bool direc, float tiempo){
	int velocidad;
	if (movY) { velocidad = VEL; } else { velocidad = -VEL; }
	nave.move(0,velocidad * tiempo);
}

void Player::OOB(sf::Vector2u tam){
	sf::Vector2f pos = nave.getPosition();
	sf::FloatRect tamCaja = nave.getLocalBounds();
	if (pos.y <= 0) { nave.setPosition(0, pos.y); movY = true; }
	if (pos.y >= tam.y - tamCaja.height) { nave.setPosition(pos.x, tam.y - tamCaja.height); movY = false; }
}

Player::~Player()
{
}
