#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Shapes/Shapes.hpp"
#include "Game.hpp"

class Game; 

class Board
{
private: 
	Game* game;

	sh::Shape* genNextShape(); 
	sh::Shape* nextShape; 
	sh::ShapeComponent* grid[20][40];
	std::vector<sh::Shape*> shapes; 
	
public: 
	Board(Game* game); 
	void Update(); 
	void draw();
	sh::Shape* currentShape;

};

