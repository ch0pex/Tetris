#include "UserInterface.hpp"

void UserInterface::Update()
{
}

void UserInterface::draw(sf::RenderWindow& window)
{

	if (state == UiState::start) {
		window.draw(_title);
		window.draw(_start);
		window.draw(_exit);
	}
	else {
		window.draw(_next);
		window.draw(_saved);
	}

	for (size_t i = 0; i < 10; i++) {
		window.draw(_contours[i], 2, sf::Lines); 
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
		{sf::Vertex(sf::Vector2f(500,100)), sf::Vertex(sf::Vector2f(700,100)) },
		{sf::Vertex(sf::Vector2f(500,300)), sf::Vertex(sf::Vector2f(700,300)) },
		{sf::Vertex(sf::Vector2f(700,100)), sf::Vertex(sf::Vector2f(700,300)) },
		{sf::Vertex(sf::Vector2f(500,700)), sf::Vertex(sf::Vector2f(900,700)) }}
{	
	state = UiState::start; 
	_currentOption = 1; 
	_font.loadFromFile("Assets/impact.ttf");

	_next.setCharacterSize(20); 
	_next.setFont(_font); 
	_next.setString("Next"); 
	_next.setPosition(sf::Vector2f(580, 75));


	_saved.setCharacterSize(20);
	_saved.setFont(_font);
	_saved.setString("Saved");
	_saved.setPosition(sf::Vector2f(580, 675));


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
