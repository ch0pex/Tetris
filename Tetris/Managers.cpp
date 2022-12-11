#include "Managers.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include<windows.h> 



void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(filename);
	textures[name] = texture;
	return;
}

sf::Texture* TextureManager::getTextureRef(const std::string& name) {
	return textures.at(name);
}


void loadShapes() {

}