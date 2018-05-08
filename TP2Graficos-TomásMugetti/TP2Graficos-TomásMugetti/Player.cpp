#include "Player.h"
#include <iostream>


Player::Player(sf::RenderWindow &_window, float	X,float Y, bool &_start, bool &_stop)
{
	window = &_window;
	start = &_start;
	stop = &_stop;
	vivo = true;
	intro = true;
	frame = true;
	cola = NULL;
	contFrame = 0;
	if (!textura.loadFromFile("Assets/Img/Nave.png"))
	{
		std::cout << "Textura de player no carga" << std::endl;
	}
	textura.setRepeated(false);
	textura.setSmooth(true);
	nave.setTexture(textura);
	nave.setTextureRect(sf::IntRect(0,0,50,50));
	nave.setPosition(X,Y);
}

void Player::Update(float elapsed){
	if (vivo)
	{
		
		
		OOB(window->getSize());
		Movimiento(elapsed);
		animar(elapsed);
		

		
		window->draw(nave);
	}
}

void Player::Movimiento(float tiempo){
	velX = 0;
	velY = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { velY -= Constantes::vel; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { velY += Constantes::vel; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { velX -= Constantes::vel *2; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { velX += Constantes::vel; }
	nave.move(velX * tiempo, velY * tiempo);
}

void Player::OOB(sf::Vector2u tam){
	sf::Vector2f pos = nave.getPosition();
	sf::FloatRect tamCaja = nave.getLocalBounds();
	if (pos.y <= 0) { nave.setPosition(pos.x, 0);}
	if (pos.y >= tam.y - tamCaja.height) { nave.setPosition(pos.x, tam.y - tamCaja.height);}
	if (pos.x <= 0){nave.setPosition(0,pos.y);}
	if (pos.x >= tam.x - tamCaja.width){nave.setPosition(tam.x - tamCaja.width, pos.y);}

	//control intro
	if (pos.x >= Constantes::introDist && intro)
	{
		intro = false;
		*start = true;
		*stop = false;
	}
}

void Player::animar(float elapsed) {
	contFrame += elapsed;
	if (contFrame >= 0.3)
	{
		contFrame = 0;
		if (frame)
		{
			nave.setTextureRect(sf::IntRect(0,0,50,50));
			nave.setTexture(textura, false);
		}
		else
		{
			nave.setTextureRect(sf::IntRect(0,50,50,50));
			nave.setTexture(textura, false);
		}
		frame = !frame;
	}
}

sf::FloatRect Player::Pos() {
	return sf::FloatRect(nave.getPosition().x,nave.getPosition().y,nave.getPosition().x + nave.getLocalBounds().width, nave.getLocalBounds().height);
}

Player::~Player()
{
}
