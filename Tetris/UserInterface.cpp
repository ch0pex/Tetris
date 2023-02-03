#include "UserInterface.hpp"

void UserInterface::Update()
{
}

void UserInterface::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 7; i++) {
		window.draw(_contours[i], 2, sf::Lines); 
	}
	if (state == UiState::start) {
		window.draw(_title);
		window.draw(_start);
		window.draw(_exit);
	}

}

void UserInterface::setOption(bool option)
{
	_currentOption = option; 
	if (option) {
		_start.setFillColor(sf::Color::Yellow);
		_exit.setFillColor(sf::Color::White);
	}
	else {
		_start.setFillColor(sf::Color::White);
		_exit.setFillColor(sf::Color::Yellow);
	}
}

bool UserInterface::getOption()
{
	return _currentOption;
}


UserInterface::UserInterface() : _contours{
		{sf::Vertex(sf::Vector2f(0,0)),     sf::Vertex(sf::Vector2f(0,1000))  },
		{sf::Vertex(sf::Vector2f(0,0)),     sf::Vertex(sf::Vector2f(500,0))   },
		{sf::Vertex(sf::Vector2f(500,0)),   sf::Vertex(sf::Vector2f(500,1000))},
		{sf::Vertex(sf::Vector2f(0,1000)),  sf::Vertex(sf::Vector2f(500,1000))},
		{sf::Vertex(sf::Vector2f(500,100)), sf::Vertex(sf::Vector2f(650,100)) },
		{sf::Vertex(sf::Vector2f(500,250)), sf::Vertex(sf::Vector2f(650,250)) },
		{sf::Vertex(sf::Vector2f(650,100)), sf::Vertex(sf::Vector2f(650,250))}}
{	
	state = UiState::start; 
	_currentOption = 1; 
	_font.loadFromFile("Assets/impact.ttf");
	_title.setCharacterSize(70);
	_title.setFont(_font);
	_title.setString("Tetris");
	_title.setPosition(sf::Vector2f(560, 400));
	_start.setCharacterSize(30);
	_start.setFont(_font);
	_start.setFillColor(sf::Color::Yellow);
	_start.setString("Start");
	_start.setPosition(sf::Vector2f(605, 510));
	_exit.setCharacterSize(30);
	_exit.setFont(_font);
	_exit.setString("Exit");
	_exit.setPosition(sf::Vector2f(615, 560));
} 
