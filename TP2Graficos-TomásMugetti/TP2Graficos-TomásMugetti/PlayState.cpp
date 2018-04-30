#include "PlayState.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>
#define SPD 200


PlayState::PlayState(sf::RenderWindow &_window, bool &init)
{
	init = true;
	window = &_window;
}


PlayState::~PlayState()
{
}

void PlayState::Start() {
	bool playing = true;
	sf::Clock clock;
	sf::Texture texturePlayer1;
	sf::Texture texturePlayer2;
	if (!texturePlayer1.loadFromFile("Assets/Img/Azul.png"))
	{
		std::cout << "Textura no carga maicol." << std::endl;
	}
	if (!texturePlayer2.loadFromFile("Assets/Img/Rojo.png"))
	{
		std::cout << "Textura no carga maicol." << std::endl;
	}
	texturePlayer1.setRepeated(false);
	texturePlayer1.setSmooth(true);
	texturePlayer2.setRepeated(false);
	texturePlayer2.setSmooth(true);

	sf::Sprite spritePlayer1;
	spritePlayer1.setTexture(texturePlayer1);
	sf::Sprite spritePlayer2;
	spritePlayer2.setTexture(texturePlayer2);

	while (playing)
	{
		window->clear();
		window->draw(spritePlayer1);
		window->draw(spritePlayer2);
		window->display();
		sf::Time elapsed = clock.restart();
		Movement(spritePlayer1, spritePlayer2, elapsed.asSeconds(), window->getSize());
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				playing = false;
				window->close();
				std::cout << "Sale por cruz" << std::endl;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			playing = false;
			std::cout << "Sale por escape" << std::endl;
		}
	}
}


void PlayState::Movement(sf::Sprite &player1, sf::Sprite &player2, float tiempo, sf::Vector2u tam) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player1.move(0, -SPD * tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player1.move(0, SPD *tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { player2.move(0, -SPD * tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { player2.move(0, SPD * tiempo); }
	//OOB(player1,tam);
	//OOB(player2, tam);
}
void PlayState::OOB(sf::Sprite &caja, sf::Vector2u tam) {
	sf::Vector2f pos = caja.getPosition();
	if (pos.y < 0){	caja.setPosition(pos.x,0);}
	if (pos.y > tam.y) { caja.setPosition(pos.x,tam.y); }
	if (pos.x < 0) { caja.setPosition(0,pos.y); }
	if (pos.x < tam.x) { caja.setPosition(tam.x,pos.y); }
}