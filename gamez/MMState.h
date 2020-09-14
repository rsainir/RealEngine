#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "DEFINITIONS.h"
#include "Game.h"

namespace RealEngine {
	
	class MMState : public State {

	public:
		MMState(GameDataPtr data);

		void Init();

		void InputHandle();
		void Update(float dt);
		void Draw(float dt);

		void MoveUp();
		void MoveDown();
		int GetPressed();

	private:
		GameDataPtr data;
		sf::Sprite background;
		sf::Sprite playButton;
		sf::Sprite buttonOuter;
		sf::Sprite title;
		sf::Font mFont;

		int selectedItemIndex;
		sf::Text menu[MAX_ITEMS];
	};

}