#include "Menu.h"

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("motherwonder.ttf")) {
		//errrorrrrr
		cout << "Font not found!!! put a valid one!" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height/(MAX_ITEMS + 1)*1)); //dynamic sizing


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Settings");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2)); //dynamic sizing

	

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Quit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3)); //dynamic sizing

	selectedItemIndex = 0;
}

Menu::~Menu() {

}


void Menu::draw(sf::RenderWindow& window) { //which window to draw to?
	for (unsigned int i = 0; i < MAX_ITEMS; i++) {
		window.draw(menu[i]); //loop through and draw all the items in the menu 
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Cyan);

	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Cyan);

	}
}

int Menu::GetPressed() {
	return selectedItemIndex;
}