#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Shapes/Shape.hpp"


enum UiState {
	start = 0, 
	playing, 
	gameOver,
	pause
};


class UserInterface
{
private: 
	sf::Text _title;
	sf::Text _start;
	sf::Text _exit;
	sf::Text _next; 
	sf::Text _saved; 
	sf::Text _score;
	sf::Text _gameOver;
	sf::Vertex _contours[8][2];
	sf::Font _font;
	bool _currentOption;


public: 

	UiState state;

	void setOption(bool option);
	bool getOption(); 

	void Update(int &score); 
	void draw(sf::RenderWindow& window);
	UserInterface(); 
};

