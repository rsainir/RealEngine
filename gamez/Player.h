#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <string>
//todo:

namespace RealEngine {
	class Player {
	public:
		
		Player(sf::Vector2f size);
		void drawTo(sf::RenderWindow& window);
		void move(sf::Vector2f distance);
		void setPos(sf::Vector2f newPos);
	private:
		sf::RectangleShape player;
	};


}