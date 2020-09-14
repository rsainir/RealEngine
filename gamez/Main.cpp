#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "DEFINITIONS.h"


int main() {
	RealEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "State of Unrest");
	return EXIT_SUCCESS;
}
