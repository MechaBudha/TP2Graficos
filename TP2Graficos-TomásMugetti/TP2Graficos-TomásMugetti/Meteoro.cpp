#include "Meteoro.h"


static sf::Texture texturaMeteoro;
static sf::Texture texturaCola;
Meteoro::Meteoro(float Y, sf::RenderWindow &_window)
{
	window = &_window;
	contador = 0;
	contFrame = 0;
	activo = false;
	sprite.setTexture(texturaMeteoro);
	sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprite.setPosition(window->getSize().x + 50, Y);
	cola.setTexture(texturaCola);
	cola.setPosition(sprite.getPosition());

}
void Meteoro::Init() {
	if (!texturaMeteoro.loadFromFile("Assets/Img/Meteoro.png")) { std::cout << "Textura meteoro no carga" << std::endl; }
	if (!texturaCola.loadFromFile("Assets/Img/MeteoroCola.png")) { std::cout << "Textura cola meteoro no carga" << std::endl; }
	texturaMeteoro.setRepeated(false);
	texturaMeteoro.setSmooth(true);
	texturaCola.setRepeated(false);
	texturaCola.setSmooth(true);
}

void Meteoro::Update(float elapsed) {
	if (activo)
	{
		sprite.move(Constantes::vel *-1.5 * elapsed, 0);
	}
	else
	{
		sprite.setPosition(window->getSize().x + 50,0);
	}
	cola.setPosition(sprite.getPosition());
	Animar(elapsed);
	window->draw(cola);
	window->draw(sprite);
}

void Meteoro::Animar(float elapsed) {
	contador += elapsed;
	if (contador >= 0.125)
	{
		contador = 0;
		contFrame++;
		switch (contFrame)
		{
		case 0:
			sprite.setTextureRect(sf::IntRect(0,0,50,50));
			break;
		case 1:
			sprite.setTextureRect(sf::IntRect(0, 50, 50, 50));
			break;
		case 2:
			sprite.setTextureRect(sf::IntRect(0, 100, 50, 50));
			break;
		case 3:
			sprite.setTextureRect(sf::IntRect(0, 150, 50, 50));
			contFrame = 0;
			break;
		default:
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
			break;
		}
	}
}

bool Meteoro::GetActivo() {
	return activo;
}

void Meteoro::SetActivo(bool act) {
	activo = act;
}

sf::FloatRect Meteoro::pos() {
	return sf::FloatRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}
Meteoro::~Meteoro()
{
}
