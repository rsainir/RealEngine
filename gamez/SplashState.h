#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "GameDataPtr.h"




namespace RealEngine {

	class SplashState : public State { //SplashState is a state

	public:
		
		SplashState(GameDataPtr data); //can access our game data through state

		void Init();

		void InputHandle();
		void Update(float dt);
		void Draw(float dt);

	private:
		
		GameDataPtr data; 

		sf::Clock clock;
		
		sf::Sprite background;
		
	};
}