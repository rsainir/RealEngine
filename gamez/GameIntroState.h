#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "GameDataPtr.h"
#include "DEFINITIONS.h"
#include "Game.h"


namespace RealEngine {


	class GameIntroState : public State {
	public:
		GameIntroState(GameDataPtr data);

		void Init();

		void InputHandle();

		void Update(float dt);
		void Draw(float dt);

		void MoveUp();
		void MoveDown();

		void MoveLeft();
		void MoveRight();
		int GetPressed();

	private:
		GameDataPtr data;  
		sf::Sprite optionSprites[CHARS];
		sf::Text options[CHARS];

		sf::Text tempShow;

		sf::Font mFont;

		sf::Text introText;
		sf::Sprite textBorder;
		sf::Sprite spriteBorder;
		sf::Sprite gameBorder;

		int selectedItemIndex;
		



	};



}