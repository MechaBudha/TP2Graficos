#ifndef FONDO_H
#define FONDO_H
#include "SFML\Graphics.hpp"
#include "Constantes.h"

class Fondo
{
	sf::Texture textura;
	sf::Sprite primero;
	sf::Sprite segundo;
	sf::Sprite *lider;
	sf::Sprite *seguidor;
	sf::RenderWindow *window;
	bool orden;
public:
	Fondo(sf::RenderWindow &_window);
	void Update(float elapsed);
	~Fondo();
};
#endif // !FONDO_H

