#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "SplashState.h"
#include "GameDataPtr.h"

//add managers here when more get created
#include "AssetManager.h"
#include "InputManager.h"



namespace RealEngine {
	struct GameData { //reminder: struct is public by default!!
		//struct holds instances of our managers/handlers and the state machine, as well as the window
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;

		bool fullScreen = false;
	};

	


	class Game {
	public:

		Game(int width, int height, string name); //width and height of screen, name of the game

	private:
		const float dt = 1.0f / 60.0f; //framreate is set to 60fps
		sf::Clock clock;
		

		//allocate memory for the data, we want it to be smart
		GameDataPtr data = make_shared<GameData>(); //allocate memory for control block and resource, avoid using "new" before passing to shared_ptr constructor

		void Start(); //starting game
	};



}