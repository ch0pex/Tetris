#include "TextureManager.hpp"


void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	sf::Texture texture; 
	texture.loadFromFile(filename); 
	textures[name] = texture; 
	return; 
}

sf::Texture TextureManager::getTextureRef(const std::string& name) {
	return textures.at(name); 
}