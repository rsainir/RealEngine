#include <sstream>
#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MMState.h"
#include <iostream>

namespace RealEngine {
	SplashState::SplashState(GameDataPtr data) {
		this->data = data;
		//can set stuff here, but we do that in init

	}

	void SplashState :: Init() {
		this->data->assets.LoadTexture("SplashBackground", SPLASH_STATE_BACKGROUND_FILEPATH);
		this->background.setTexture(this->data->assets.GetTexture("SplashBackground"));
	}

	void SplashState::InputHandle() {
		sf::Event event;
		
		while (this->data->window.pollEvent(event)) {

			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
		}
	}

	void SplashState::Update(float dt) {
		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			//switch to main menu 
			this->data->machine.PushState(StateRef(new MMState(this->data)), true); //pass data to a new state, replace old state 
		}
	}

	void SplashState::Draw(float dt) { //actually displaying stuff
		this->data->window.clear(sf::Color::Green);
		this->data->window.draw(this->background);
		this->data->window.display();
	}

}