#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Shapes/Shape.hpp"


class Board
{
private: 
	sf::Text title;
	sf::Text start;
	sf::Text exit;
	sf::Vertex contours[7][2];
	sf::Font font;
	bool currentOption; 

public: 
	void draw(sf::RenderWindow& window);
	Board(); 
};

