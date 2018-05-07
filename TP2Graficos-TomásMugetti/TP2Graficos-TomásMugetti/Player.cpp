#include "Player.h"
#include <iostream>


Player::Player(sf::RenderWindow &_window, float	X,float Y, bool &_start, bool &_stop)
{
	window = &_window;
	start = &_start;
	stop = &_stop;
	movY = true;
	vivo = true;
	orden = true;
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
		animar(elapsed);
		window->draw(nave);

		if (cola == NULL)
		{
			Trazo::Trazo(nave,cola);
		}
		else
		{
			if (cola != nullptr)
			{
				if (!Trazo::TocaFuente(*cola, nave))
				{
					Trazo::Trazo(nave, cola);
				}
				Trazo::Trazar(elapsed, *window);
			}
		}
			
	}
}

void Player::Movimiento(bool direc, float tiempo){
	int velocidad;
	if (movY) { velocidad = Constantes::vel; } else { velocidad = -Constantes::vel; }
	if (intro){	
		nave.move(velocidad * tiempo, velocidad * tiempo);
	}else { nave.move(0, velocidad * tiempo); }
}

void Player::OOB(sf::Vector2u tam){
	sf::Vector2f pos = nave.getPosition();
	sf::FloatRect tamCaja = nave.getLocalBounds();
	if (pos.y <= 0) { nave.setPosition(pos.x, 0); movY = true; }
	if (pos.y >= tam.y - tamCaja.height) { nave.setPosition(pos.x, tam.y - tamCaja.height); movY = false; }

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
