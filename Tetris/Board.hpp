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
	sh::Shape* _nextShape; 
	sh::Shape* _extraShape; 
	std::vector<sh::Shape*> _shapes;
	int _score;

	sh::Shape* genNextShape(); 
	void shapeToGrid(sh::Shape* currentShape);
	void gravity(); 
	bool checkPlaced(); 
	void deleteRow(int y);
	int checkGameOver(); 

public: 
	sh::ShapeComponent* grid[10][20] = {nullptr};
	Board(Game* game); 
	int Update(); 
	void draw();
	void swapShapes(); 

	sh::Shape* currentShape;


};

