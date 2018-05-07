#include "ControlMeteoro.h"



ControlMeteoro::ControlMeteoro(sf::RenderWindow &_window, Player &_jugador)
{
	Meteoro::Init();
	srand(time(0));
	contador = 0;
	tempo = 0;
	cuentaMet = 0;
	window = &_window;
	jugador = &_jugador;
	for (int i = 0; i < TAM; i++)
	{
		grupo[i] = new Meteoro(_window);
		grupo[i]->SetActivo(false);
	}
}

void ControlMeteoro::Update(float elapsed) {
	tempo += elapsed;
	if (tempo >= 1.5) { contador++; tempo = 0; cuentaMet = 0; }
	
	for (int i = 0; i < TAM; i++)
	{
		if (cuentaMet < contador && !(grupo[i]->GetActivo())) {
			grupo[i]->Init(rand()%(Constantes::ALTOPANTALLA - 50));
			cuentaMet++;
			std::cout << cuentaMet << " " << contador << " " << tempo << std::endl;
		}
		if (grupo[i]->GetActivo())
		{
			grupo[i]->Update(elapsed);
		}
		
	}
}


ControlMeteoro::~ControlMeteoro()
{
}
