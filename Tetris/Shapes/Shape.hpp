#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"


class Shape
{
private: 
	std::vector<sf::Sprite> sprites; 
public: 
	virtual void rotateShape() = 0; 
	virtual void accelShape() = 0;

};

