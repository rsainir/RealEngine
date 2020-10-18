#include "GameIntroState.h"
#include "MMState.h"
#include "GameState.h"

namespace RealEngine {

	GameIntroState::GameIntroState(GameDataPtr data) {
		this->data = data;
	}

	void GameIntroState::Init() {
		this->data->assets.LoadFont("MotherFont", MOTHER_FONT_PATH);
		tempShow.setFont(this->data->assets.GetFont("MotherFont"));
		tempShow.setFillColor(sf::Color::White);
		tempShow.setString("Welcome to the game, press spacebar to continue!");
		tempShow.setPosition(sf::Vector2f((SCREEN_WIDTH / 2)-tempShow.getGlobalBounds().width*1.5, SCREEN_HEIGHT * 0.4));
		
		tempShow.setCharacterSize(90);

	}

	void GameIntroState::InputHandle() {
		sf::Event event;

		while (this->data->window.pollEvent(event)) {

			switch (event.type) { //switch for all diff event types

			case sf::Event::KeyReleased: //event for key release
				//all the keys that can be released 
				switch (event.key.code) {

				case sf::Keyboard::Up:
					this->MoveUp();
					break;

				case sf::Keyboard::Down:
					this->MoveDown();
					break;

				case sf::Keyboard::Escape:
					this->data->machine.PushState(StateRef(new MMState(this->data)), true);
					break;
				case sf::Keyboard::Space:
					this->data->machine.PushState(StateRef(new GameState(this->data)), true);
					break;
				case sf::Keyboard::Return:
					switch (this->GetPressed()) {
					case 0:
						//todo
						break;
					case 1:
						//todo
						break;
					}
					break;
				}
				break;

			case sf::Event::Closed:
				this->data->window.close();
				break;
			}
			//do keyboard stuff here for the menu 
		}
	}


	void GameIntroState::Update(float dt) {

	}

	void GameIntroState::Draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->tempShow);

		this->data->window.display();
	}

	void GameIntroState::MoveUp() {

	}

	void GameIntroState::MoveDown() {

	}

	void GameIntroState::MoveLeft() {

	}

	void GameIntroState::MoveRight() {

	}

	int GameIntroState::GetPressed() {
		return 0;
	}

}