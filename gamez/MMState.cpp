#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "MMState.h"
#include "SettingsState.h"

//todo: clean up pointers, delete allocated memory!! we dont want memory leaks
namespace RealEngine {
	MMState::MMState(GameDataPtr data) {
		this->data = data;
	}

	void MMState::Init() {
		//this->data->assets.LoadTexture("MainMenuBackground", MM_BACKGROUND_FILEPATH);
		//this->background.setTexture(this->data->assets.GetTexture("MainMenuBackground"));

		//this->data->assets.LoadTexture("PlayButton", PLAY_BUTTON_FILEPATH);
		//this->playButton.setTexture(this->data->assets.GetTexture("PlayButton"));

		this->data->assets.LoadTexture("Title", MM_TITLE_FILEPATH);
		this->title.setTexture(this->data->assets.GetTexture("Title"));

		//this->data->assets.LoadTexture("PBOuter", PLAY_BUTTON_OUTER);
		//this->playButton.setTexture(this->data->assets.GetTexture("PBOuter"));

		this->data->assets.LoadFont("MotherFont", MOTHER_FONT_PATH);
		
		

		menu[0].setFont(this->data->assets.GetFont("MotherFont"));
		menu[0].setFillColor(sf::Color::Red);
		menu[0].setString("Play");
		menu[0].setPosition(sf::Vector2f(SCREEN_WIDTH *0.75, SCREEN_HEIGHT / (MAX_ITEMS + 1) * 1)); //dynamic sizing

		menu[1].setFont(this->data->assets.GetFont("MotherFont"));
		menu[1].setFillColor(sf::Color::White);
		menu[1].setString("Settings");
		menu[1].setPosition(sf::Vector2f(SCREEN_WIDTH *0.75, SCREEN_HEIGHT / (MAX_ITEMS + 1) * 2)); //dynamic sizing

		menu[2].setFont(this->data->assets.GetFont("MotherFont"));
		menu[2].setFillColor(sf::Color::White);
		menu[2].setString("Exit");
		menu[2].setPosition(sf::Vector2f(SCREEN_WIDTH *0.75, SCREEN_HEIGHT / (MAX_ITEMS + 1) * 3)); //dynamic sizing

		for (unsigned int i = 0; i < MAX_ITEMS; i++) {
			menu[i].setCharacterSize(60);
		}

		selectedItemIndex = 0;

		//position play button in the middle
		//this->playButton.setPosition((SCREEN_WIDTH / 2) - (this->playButton.getGlobalBounds().width / 2),
		//	(SCREEN_HEIGHT / 2) - (this->playButton.getGlobalBounds().height / 2));
		//this->buttonOuter.setPosition((SCREEN_WIDTH / 2) - (this->playButton.getGlobalBounds().width / 2),
		//	(SCREEN_HEIGHT / 2) - (this->buttonOuter.getGlobalBounds().height / 2));

		////center in x axis, towards top in y axis
		this->title.setPosition((SCREEN_WIDTH* 0.37) - (this->title.getGlobalBounds().width / 2),
		this->title.getGlobalBounds().height* 1.25); //dynamic
	}

	void MMState::InputHandle() {
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

				case sf::Keyboard::Return:
					switch (this->GetPressed()) {
					case 0:
						cout << "switch to game state here!" << endl;
						break;
					case 1:
						//replace state in state machine w/ settings state
						this->data->machine.PushState(StateRef(new SettingsState(this->data)), true);
						//can possibly manually call destructor? find out where we want to deallocate data
						break;
					case 2:
						this->data->window.close();
						break; //wont reach this break but whatever lol
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

	void MMState::Update(float dt) {

	}

	void MMState::Draw(float dt) {
		this->data->window.clear();

		for (unsigned int i = 0; i < MAX_ITEMS; i++) {
			this->data->window.draw(menu[i]); //loop through and draw all the items in the menu 
		}

		/*this->data->window.draw(this->background);
		this->data->window.draw(this->playButton);
		this->data->window.draw(this->buttonOuter);
		*/
		this->data->window.draw(this->title);

		this->data->window.display();

	}

	void MMState::MoveUp() {
		if (selectedItemIndex - 1 >= 0) {
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			menu[selectedItemIndex].setFillColor(sf::Color::Red);

		}
	}

	void MMState::MoveDown() {
		if (selectedItemIndex + 1 < MAX_ITEMS) {
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			menu[selectedItemIndex].setFillColor(sf::Color::Red);

		}
	}

	int MMState::GetPressed() {
		return selectedItemIndex;
	}



}