#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#define MAX_ITEMS 3


using namespace std;

class Menu {
public:
	Menu(float width, float height);
	~Menu();


	void draw(sf::RenderWindow& window); //draw to the window we have (pass by reference)
	void MoveUp();
	void MoveDown();
	int GetPressed();


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_ITEMS]; //array that holds text containing menu items 
};