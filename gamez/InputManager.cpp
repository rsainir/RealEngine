#include "InputManager.h"

/// <summary>
/// do something like this for keyboard input???? events/real time input
/// </summary>
namespace RealEngine {
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) {

		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (tempRect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}
		}
		return false;
	}
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window);

	}
}