#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>
#define SPD 200

void movement(sf::Sprite &player1, sf::Sprite &player2, float tiempo) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player1.move(0, -SPD * tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player1.move(0, SPD *tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { player2.move(0, -SPD * tiempo); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { player2.move(0, SPD * tiempo); }

}
void main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
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

	while (window.isOpen())
	{
		window.clear();
		window.draw(spritePlayer1);
		window.draw(spritePlayer2);
		window.display();
		sf::Time elapsed = clock.restart();
		movement(spritePlayer1, spritePlayer2, elapsed.asSeconds());
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}