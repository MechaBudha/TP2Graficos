#ifndef TRAZO_H
#define TRAZO_H
#include "SFML\Graphics.hpp"
#include "Constantes.h"
#include <array>
class Trazo
{
	//static int contador;
	//static std::array < sf::Sprite, Constantes::introDist + 1> trazos;
public:
	Trazo(sf::Sprite fuente,sf::Sprite *&cola);
	~Trazo();
	static bool TocaFuente(sf::Sprite sprite, sf::Sprite fuente);
	static void Trazar(float elapsed, sf::RenderWindow &window);
};
#endif // !TRAZO_H

