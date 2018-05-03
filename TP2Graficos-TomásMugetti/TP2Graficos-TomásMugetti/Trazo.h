#ifndef TRAZO_H
#define TRAZO_H

#include "Constantes.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
class Trazo
{
	
	bool debeMorir;
	sf::Texture textura;
	sf::Sprite sprite;
	sf::Sprite *fuente;
public:
	static float elapsed;
	static sf::RenderWindow *window;
	Trazo(sf::Sprite &_fuente, bool direc);
	void Update();
	bool TocaFuente();
	~Trazo();
};
#endif // !TRAZO_H

