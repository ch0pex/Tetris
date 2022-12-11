#include "Board.hpp"

void Board::draw(sf::RenderWindow& window,)
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
	font.loadFromFile("Assets/impact.ttf");
	title.setCharacterSize(70);
	title.setFont(font);
	title.setString("Tetris");
	title.setPosition(sf::Vector2f(560, 400));
	start.setCharacterSize(30);
	start.setFont(font);
	start.setFillColor(sf::Color::Yellow);
	start.setString("Start");
	start.setPosition(sf::Vector2f(605, 510));
	exit.setCharacterSize(30);
	exit.setFont(font);
	exit.setString("Exit");
	exit.setPosition(sf::Vector2f(615, 560));
} 
