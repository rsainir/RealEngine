#include "AssetManager.h"

namespace RealEngine {
	void AssetManager::LoadTexture(string name, string fileName) { //texture loader/getter
		sf::Texture tex;

		if (tex.loadFromFile(fileName)) {
			this  -> textures[name] = tex;
		}
		else {
			cout << "Texture" << fileName << "NOT FOUND" << endl;
		}
	}
	sf::Texture& AssetManager::GetTexture(string name) {
		return this->textures.at(name);
	}


	void AssetManager::LoadFont(string name, string fileName) { //font loader/getter
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->fonts[name] = font;
		}
		else {
			cout << "FONT " << fileName << "NOT FOUND" << endl;
		}
	}
	sf::Font& AssetManager::GetFont(string name) {
		return this->fonts.at(name);
	}

	void AssetManager::LoadAudio(string name, string fileName){ //sound loader
		sf::SoundBuffer soundBuff;

		if (soundBuff.loadFromFile(fileName)) {
			this->sounds[name] = soundBuff;
		}
		else {
			cout << "sound " << fileName << " not found!" << endl;
		}
	}

	sf::SoundBuffer& AssetManager::GetSound(string name) { //sound getter
		return this->sounds.at(name);
	}



	//More assets: load and get audio
}