#include "PlayState.h"




PlayState::PlayState(sf::RenderWindow &_window, bool &_win)
{
	start = false;
	stop = false;
	win = &_win;
	window = &_window;
}


PlayState::~PlayState()
{
}

void PlayState::Play() {
	//utilidad
	bool playing = true;
	sf::Clock clock;
	sf::Time tiempo;
	float elapsed;

	//entidades
	
	Player* jugador = new Player(*window, 0,0, start, stop);
	Fondo* fondo = new Fondo(*window);
	ControlMeteoro* control = new ControlMeteoro(*window, *jugador, playing);

	//gameloop
	while (playing)
	{
		//comienzo ciclo nuevo en limpio
		tiempo = clock.restart();
		elapsed = tiempo.asSeconds();
		window->clear();


		//updates
		fondo->Update(elapsed);
		jugador->Update(elapsed);
		control->Update(elapsed);


		//una vez dibujado todo
		window->display();


		//eventos de salida
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
			window->clear();
			std::cout << "Sale por escape" << std::endl;
		}
	}
}

