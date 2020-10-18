#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "GameDataPtr.h"
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

using namespace std;


namespace RealEngine {

	class GameState : public State {
	public:
		GameState(GameDataPtr data);

		void Init();

		void InputHandle();

		void Update(float dt);
		void Draw(float dt);

		void SpriteLeft(sf::Sprite &target);
		void SpriteRight(sf::Sprite &target);

		void SpriteJump(sf::Sprite& target);

	private:
		GameDataPtr data;
		sf::Font mFont;
		sf::Text text;
		sf::View view;


		sf::Texture textBox;

		vector <sf::Sprite> sprites; //vector to render all our sprites together
		
		
		
		//changed to vector of objects/characters with their own attributes and sprites

		sf::Sprite mainSprite;
	
		//sf::Sprite sprites[SP_CEILING]; //arraay of sprites

	};

}