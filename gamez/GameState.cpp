#include "GameState.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include "GameDataPtr.h"
#include "DEFINITIONS.h"
#include "Game.h"

namespace RealEngine {

		GameState::GameState(GameDataPtr data) {
			this->data = data;
			sf::View _view(sf::FloatRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT)); //left, top, width, height
			this->view = _view;
		}

		void GameState::Init() {
			this->data->assets.LoadFont("QuickFont", GAME_FONT_PATH);
			
			text.setFont(this->data->assets.GetFont("QuickFont"));
			text.setFillColor(sf::Color::White);
			text.setString("Use the arrow keys or WASD to move, space to jump");
			text.setCharacterSize(40);
			text.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

			this->data->assets.LoadTexture("MainSprite", MAIN_SPRITE_PATH);

			this->mainSprite.setTexture(this->data->assets.GetTexture("MainSprite"));
			this->mainSprite.setScale(sf::Vector2f(0.2f, 0.2f));
			this->mainSprite.setPosition(0, 0);
			
			sprites.push_back(mainSprite);
			
		}
		void GameState::InputHandle() {

			sf::Event event;


			while (this->data->window.pollEvent(event)) {

				switch (event.type) { //switch for all diff event types

				case sf::Event::KeyPressed: //event for key release
					//all the keys that can be released 
					switch (event.key.code) {
					case sf::Keyboard::Right:
						//move right for main sprite
						//this->SpriteRight(sprites[0]);
						break;
					case sf::Keyboard::Left:
						//move left for main sprite
			
						//this->SpriteLeft(sprites[0]);
						break;
					case sf::Keyboard::Escape:
						//pause state, keep gamestate on stack

						break;
					case sf::Keyboard::Space:
						//this->SpriteJump(sprites[0]);
						break;
					}
					break;
				case sf::Event::KeyReleased:
					//this->view.reset(sf::FloatRect(200, 200, 400, 600));
					//view.setCenter(sf::Vector2f(350, 350));
					//view.setSize(150, 30);
					if (sf::Keyboard::Key::W == event.key.code) {
						view.move(sf::Vector2f(0, -50)); //negative up, positive down
					}
					else if (sf::Keyboard::Key::S == event.key.code) {
						view.move(sf::Vector2f(0, 50)); //negative up, positive down
					}
					else if (sf::Keyboard::Key::D == event.key.code) {
						view.move(sf::Vector2f(1920, 0)); //negative up, positive down
					}
					if (sf::Keyboard::Key::A == event.key.code) {
						view.move(sf::Vector2f(-1920, 0)); //negative up, positive down
						std::cout << "hell" << endl;
					}
					break;
				case sf::Event::Closed:
					this->data->window.close();
					break;
				}
				//do keyboard stuff here for the menu 
			}

		}

		void GameState::Update(float dt) {
		

			//cout << sprites[0].getPosition().y << endl;


			

			//gravity shit
				
			int groundHeight = 1000;
			const float gravity = 10.0f;
			float moveSpeed = 10.0f, jumpSpeed = 30.0f;
			sf::Vector2f velocity(sf::Vector2f(0, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				velocity.x = moveSpeed;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				velocity.x = -moveSpeed;
			} 
			else {
				velocity.x = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sprites[0].getPosition().y ) {
				velocity.y = -jumpSpeed;
			}

			if (sprites[0].getPosition().y + sprites[0].getTextureRect().height < groundHeight || velocity.y < 0 && sprites[0].getPosition().y) { //IF IN THE AIR
				velocity.y += gravity;
			}
			else {
				sprites[0].setPosition(sprites[0].getPosition().x, groundHeight - sprites[0].getTextureRect().height);
				velocity.y = 0;
			}

			sprites[0].move(velocity.x, velocity.y);
		




			//view stuff
			auto rect = sprites[0].getGlobalBounds();
			cout << sprites[0].getPosition().x << "and " << view.getSize().x << endl;
			//if (view.getSize().x == sprites[0].getPosition().x) {

			if (fmod(sprites[0].getPosition().x, view.getSize().x) == 0 && (sprites[0].getPosition().x >= view.getSize().x)) {
				//cout << "YO WE GOT A WINNER" << endl;
				if (velocity.x > 0) {
					view.move(sf::Vector2f(SCREEN_WIDTH, 0));
					cout << "moving forward" << endl;
				}
			}
	
			
		}

		void GameState::Draw(float dt) {
			this->data->window.setView(this->view);
			this->data->window.clear();
			
			for (unsigned int i = 0; i < sprites.size(); i++) { //let us render multiple sprites
				this->data->window.draw(sprites[i]);
			}

			this->data->window.display();
		}

		//void GameState::SpriteLeft(sf::Sprite &target) {
		//	target.move(sf::Vector2f(-10, 0));
		//}

		//void GameState::SpriteRight(sf::Sprite &target) {
		//	target.move(sf::Vector2f(10, 0));
		//}

		//void GameState::SpriteJump(sf::Sprite& target){
		//	target.move(sf::Vector2f(0, -50));
		//}

	


}