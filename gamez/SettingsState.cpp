#include "SettingsState.h"

namespace RealEngine{


	SettingsState::SettingsState(GameDataPtr data) {
		this->data = data;
	}

	void SettingsState::Init() {
		this->data->assets.LoadFont("MotherFont", MOTHER_FONT_PATH);

		menu[0].setFont(this->data->assets.GetFont("MotherFont"));
		menu[0].setFillColor(sf::Color::Red);
		menu[0].setString("Toggle Fullscreen"); //add checkbox for if its full scxreen or not, check how to make full screen
		menu[0].setPosition(sf::Vector2f(SCREEN_WIDTH * 0.395, SCREEN_HEIGHT / (MAX_ITEMS + 1) * 1));

		menu[1].setFont(this->data->assets.GetFont("MotherFont"));
		menu[1].setFillColor(sf::Color::White);
		menu[1].setString("Back to Main Menu");
		menu[1].setPosition(sf::Vector2f(SCREEN_WIDTH * 0.4, SCREEN_HEIGHT / (MAX_ITEMS + 1) * 2));

		for (unsigned int i = 0; i < OPTIONS_ROWS; i++) {
			menu[i].setCharacterSize(60);
		}

		selectedItemIndex = 0;

	}


	void SettingsState::InputHandle() {
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

				case sf::Keyboard::Return:
					switch (this->GetPressed()) {
					case 0:
						this->data->fullScreen = !this->data->fullScreen; //switch to fullscreen mode, state is preserved so this is fine
						if (this->data->fullScreen) {
							this->data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "State of Unrest", sf::Style::Fullscreen|sf::Style::Close);
						}
						else {
							this->data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "State of Unrest", sf::Style::Resize|sf::Style::Close);
						}
						break;
					case 1:
						this->data->machine.PushState(StateRef(new MMState(this->data)), true);
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
	void SettingsState::Update(float dt) {

	}

	void SettingsState::Draw(float dt) {
		this->data->window.clear();
		for (unsigned int i = 0; i < OPTIONS_ROWS; i++) {
			this->data->window.draw(menu[i]);
		}

		this->data->window.display();
	}


	void SettingsState::MoveUp() {
		if (selectedItemIndex - 1 >= 0) {
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			menu[selectedItemIndex].setFillColor(sf::Color::Red);

		}
	}

	void SettingsState::MoveDown() {
		if (selectedItemIndex + 1 < OPTIONS_ROWS) {
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			menu[selectedItemIndex].setFillColor(sf::Color::Red);

		}
	}

	int SettingsState::GetPressed() {
		return selectedItemIndex;
	}
}