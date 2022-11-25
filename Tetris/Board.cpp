#include "Board.hpp"


void Board::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 7; i++) {
		window.draw(contours[i], 2, sf::Lines); 
	}
}


Board::Board() : contours{
		{sf::Vertex(sf::Vector2f(0,0)),     sf::Vertex(sf::Vector2f(0,1000))  },
		{sf::Vertex(sf::Vector2f(0,0)),     sf::Vertex(sf::Vector2f(500,0))   },
		{sf::Vertex(sf::Vector2f(500,0)),   sf::Vertex(sf::Vector2f(500,1000))},
		{sf::Vertex(sf::Vector2f(0,1000)),  sf::Vertex(sf::Vector2f(500,1000))},
		{sf::Vertex(sf::Vector2f(500,100)), sf::Vertex(sf::Vector2f(650,100)) },
		{sf::Vertex(sf::Vector2f(500,250)), sf::Vertex(sf::Vector2f(650,250)) },
		{sf::Vertex(sf::Vector2f(650,100)), sf::Vertex(sf::Vector2f(650,250))}}
{
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 10; j++) {
			grid[i][j] = 0; 
		}
	}
} 
