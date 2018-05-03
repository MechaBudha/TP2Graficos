#include "Trazo.h"
#include <iostream>


Trazo::Trazo(sf::Sprite &_fuente, bool direc)
{
	fuente = &_fuente;
	debeMorir = false;
	if (!textura.loadFromFile("Assets/Img/Trazo.png"))
	{
		std::cout << "Textura de trazo no carga" << std::endl;
	}
	textura.setRepeated(false);
	textura.setSmooth(false);
	sprite.setTexture(textura);
	if (!direc)
	{
		sprite.setScale(-1, 1);
	}
	sprite.setPosition(fuente->getPosition().x,fuente->getPosition().y);
	while (this)
	{
		Update();
	}
}

void Trazo::Update() {
	sprite.move(Constantes::vel * -1 * elapsed, 0);
	window->draw(sprite);
	if (sprite.getPosition().x + sprite.getLocalBounds().width <= 0){delete this;}
}

bool Trazo::TocaFuente() {
	float xMin = fuente->getPosition().x;
	float xMax = fuente->getPosition().x + fuente->getLocalBounds().width;
	float yMin = fuente->getPosition().y;
	float yMax = fuente->getPosition().y + fuente->getLocalBounds().height;
	sf::Vector2f pos = sprite.getPosition();
	if ((pos.x > xMin && pos.x < xMax) && (pos.y > yMin && pos.y < yMax))
	{
		return true;
	}
	else
	{
		return false;
	}
}


Trazo::~Trazo()
{
}
