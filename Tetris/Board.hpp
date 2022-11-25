#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"



class Board
{
private: 
	sf::Vertex contours[7][2];
public: 
	void draw(sf::RenderWindow& window);
	bool grid[20][10]; 
	Board(); 
};

