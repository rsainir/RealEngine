#include "Game.h"


namespace RealEngine {
	Game::Game(int width, int height, string name) {
		data->window.create(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Titlebar); //context settings, creating window with specified size
		this->Start();
	}

	void Game::Start() {
		float frameTime, newTime, interp;
		
		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->data->window.isOpen()) { //more structured loop like the one in main.cpp
			this->data->machine.ProcessStateChanges(); //state machine, process changes (switched state, paused state, etc)

			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime; //handles differences in frametimes when frames jump around/arent steady

			if (frameTime > 0.25f) {
				frameTime = 0.25;
			}
			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator > dt) {
				this->data->machine.GetActiveState()->InputHandle();
				this->data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}
			interp = accumulator / dt;
			this->data->machine.GetActiveState()->Draw(interp);

		}


	}

}