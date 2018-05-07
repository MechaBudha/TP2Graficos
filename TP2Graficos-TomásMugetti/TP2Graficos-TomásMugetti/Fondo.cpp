#include "Fondo.h"



Fondo::Fondo(sf::RenderWindow &_window)
{
	window = &_window;
	textura.loadFromFile("Assets/Img/background.png");
	textura.setRepeated(false);
	textura.setSmooth(true);
	primero.setTexture(textura);
	segundo.setTexture(textura);
	primero.setPosition(0,0);
	segundo.setPosition(primero.getPosition().x + primero.getLocalBounds().width,0);
	orden = true;
}

void Fondo::Update(float elapsed) {
	if (orden){	lider = &primero;seguidor = &segundo;}else{	lider = &segundo;seguidor = &primero;}
	lider->move(Constantes::vel * -1 * elapsed, 0);
	seguidor->setPosition(lider->getPosition().x + lider->getLocalBounds().width, lider->getPosition().y);
	if (lider->getPosition().x + lider->getLocalBounds().width <= 0) { orden = !orden; lider->setPosition(0,0); }
	window->draw(primero);
	window->draw(segundo);
}

Fondo::~Fondo()
{
}
