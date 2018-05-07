#ifndef METEORO_H
#define METEORO_H
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Constantes.h"
class Meteoro
{
	sf::Sprite sprite;
	sf::Sprite cola;
	sf::RenderWindow *window;
	float contador;
	int contFrame;
	bool activo;
public:
	Meteoro(float Y, sf::RenderWindow &_window);
	static void Init();
	sf::FloatRect pos();
	bool GetActivo();
	void SetActivo(bool act);
	void Animar(float elapsed);
	void Update(float elapsed);

	~Meteoro();
};
#endif // !METEORO_H

