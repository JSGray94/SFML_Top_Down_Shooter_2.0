#pragma once

#include <memory>
#include <map>
#include <SFML\Graphics.hpp>

namespace Textures
{
	enum ID{ Landscape, Airplane, Missle };
}

class TextureHolder
{
public:
	TextureHolder();
	void load(Textures::ID id, const std::string& fileName);
	sf::Texture& get(Textures::ID id);

	//Create a texture map which contains an ID and a unique pointer pointing to the texture (Saves creating copies).
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

};

