#pragma once
#include "GameState.hpp"
#include "Board.hpp"
#include "Shapes/Shape.hpp"
#include <list>
#include <iostream>

class GameStatePlaying : public GameState
{
private: 
	std::list<sh::Shape> shapes; 


public: 
	virtual void Draw();
	virtual void HandleInput();
	virtual void Update();
	//virtual void fixedUpdate(); 

	GameStatePlaying(Game* game);
};

