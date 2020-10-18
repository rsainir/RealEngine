#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "GameDataPtr.h"
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>
 
//todo: learn how to use update function for character class and game state

namespace RealEngine {

	class PauseState : public State {
	public:
		PauseState(GameDataPtr data);

		void Init();

		void InputHandle();
		void Update(float dt);
		void Draw(float dt);

		void GetPressed();
		void MoveUp();
		void MoveDown();

	private:
		GameDataPtr data;
		int selectedItemIndex;
		sf::Sprite background;
		sf::Font font;
		sf::Text pauseText;
		sf::Text choices[CHOICE_NUM]; //resume, quit to main menu, quit to desktop, settings

		//add weapon stats, character stats 

	};


}
