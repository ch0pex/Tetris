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
	std::vector<sh::Shape*> shapes;
	int checkTicks; 

	sh::Shape* genNextShape(); 
	void shapeToGrid(sh::Shape* currentShape);
	void gravity(); 
	bool checkPlaced(); 
	void deleteRow(int y);
public: 
	sh::ShapeComponent* grid[10][20] = {nullptr};
	Board(Game* game); 
	void Update(); 
	void draw();
	sh::Shape* currentShape;

};

