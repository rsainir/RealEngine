#include <SFML/Graphics.hpp>
#include "State.h"
#include "DEFINITIONS.h"
#include "Game.h"

namespace RealEngine {

	class SettingsState : public State {
	public:
		SettingsState(GameDataPtr data);
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


		int selectedItemIndex;

		sf::Text menu[OPTIONS_ROWS][OPTIONS_COLS]; //6 options in menu, want in 2d array


	};





}