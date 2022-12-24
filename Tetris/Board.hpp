#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Shapes/Shapes.hpp"
#include "Game.hpp"

class Game; 

class Board
{
private: 
	Game* game;
	//sh::Shape* storedShape; 
	sh::Shape* nextShape; 
	sh::ShapeComponent* grid[10][20] = {nullptr};
	std::vector<sh::Shape*> shapes;
	std::thread* fixedUpdate; 

	sh::Shape* genNextShape(); 
	void shapeToGrid(sh::Shape* currentShape);
	void gravity(); 

public: 
	Board(Game* game); 
	void Update(); 
	void draw();
	sh::Shape* currentShape;

};

