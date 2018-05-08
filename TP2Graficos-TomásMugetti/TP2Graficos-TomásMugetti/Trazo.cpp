#include "Trazo.h"
#include <iostream>

static int contador;
static std::array < sf::Sprite, Constantes::introDist*2 + 1> trazos;
static sf::Texture textura;
Trazo::Trazo(sf::Sprite fuente,sf::Sprite *&cola)
{
	sf::Sprite sprite;
	if (!textura.loadFromFile("Assets/Img/Trazo.png"))
	{
		std::cout << "Textura Trazo no carga" << std::endl;
	}
	textura.setRepeated(false);
	textura.setSmooth(true);
	sprite.setTexture(textura);
	sprite.setPosition(fuente.getPosition());
	if (trazos.empty())
	{
		contador = 0;
	}
	trazos[contador] = sprite;
	cola = &trazos[contador];
	contador++;
	if (contador >= Constantes::introDist*2 + 1)
	{
		contador = 0;
	}
}

Trazo::~Trazo()
{
}

void Trazo::Trazar(float elapsed, sf::RenderWindow &window) {
	if (!trazos.empty())
	{
		for (int i = 0; i <  Constantes::introDist*2+1; i++) {
			trazos[i].move(Constantes::vel*-1 * elapsed, 0);
			window.draw(trazos[i]);
		}
	}
}



bool Trazo::TocaFuente(sf::Sprite sprite, sf::Sprite fuente) {
	sf::Vector2f spritePos = sprite.getPosition();
	sf::Vector2f fuentePos = fuente.getPosition();
	sf::FloatRect spriteTam = sprite.getLocalBounds();
	sf::FloatRect fuenteTam = fuente.getLocalBounds();
	if (spritePos.x > fuentePos.x - (spriteTam.width/2) && spritePos.x < fuentePos.x + fuenteTam.width + (spriteTam.width/2))
	{
		return true;
	}
	else
	{
		return false;
	}
}