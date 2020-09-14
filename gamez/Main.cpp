#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "DEFINITIONS.h"


int main() {
	RealEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "State of Unrest");
	return EXIT_SUCCESS;
}


//int main() {
//	sf::RenderWindow window(sf::VideoMode(800, 600), "State of Unrest");
//
//	Menu menu(window.getSize().x, window.getSize().y); //size of window w/ x and y , makes it dynamic with window changing size
//	
//
//	while (window.isOpen()) {
//		sf::Event event;
//
//		while (window.pollEvent(event)) {
//			switch (event.type) {
//
//			case sf::Event::KeyReleased: //new case: event for key release
//				switch (event.key.code) {//which key pressed?
//				case sf::Keyboard::Up:
//					menu.MoveUp();
//					break;
//
//				case sf::Keyboard::Down:
//					menu.MoveDown();
//					break;
//
//				case sf::Keyboard::Return:
//					switch (menu.GetPressed()) {
//					case 0:
//						cout << "Player wants to play!!" << endl;
//						break;
//					case 1:
//						cout << "Lemme edit some settings bruv 3Head" << endl;
//						break;
//					case 2:
//						cout << "O shit cya" << endl;
//						window.close();
//						break;
//					}
//					break;
//
//
//
//				}
//				break;
//			case sf::Event::Closed:
//				window.close();
//				break;
//			}
//
//		}
//
//		window.clear();
//
//		menu.draw(window); //draw to the window 
//
//		window.display();
//	}
//
//
//
//
//
//
//
//	return 0;
//}