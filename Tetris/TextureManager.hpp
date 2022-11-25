#include "SFML-2.5.1/include/SFML/Graphics.hpp"

#pragma once
class TextureManager
{
private: 
	std::map<std::string, sf::Texture> textures;
public: 
	void loadTexture(const std::string& name, const std::string& filename); 
	sf::Texture getTextureRef(const std::string& name); 
};

