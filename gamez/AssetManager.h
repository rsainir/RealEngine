#pragma once

#include <map> //fonts and textures
#include <iostream>

#include <SFML/Graphics.hpp> //graphics
#include <SFML/Audio.hpp>


using namespace std;

namespace RealEngine {
	class AssetManager {
	public:
		AssetManager() {}; //empty
		~AssetManager() {};

		void LoadTexture(string name, string fileName);
		sf::Texture& GetTexture(string name);

		void LoadFont(string name, string fileName);
		sf::Font& GetFont(string name);

		void LoadAudio(string name, string fileName);
		sf::SoundBuffer& GetSound(string name);

		
	private:
		std::map <string, sf::Texture> textures;
		std::map<string, sf::Font> fonts;
		std::map<string, sf::SoundBuffer> sounds;

	};
}