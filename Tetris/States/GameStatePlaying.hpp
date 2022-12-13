#pragma once
#include "GameState.hpp"
#include "../Shapes/Shape.hpp"
#include "../Board.hpp"
#include <list>
#include <iostream>

class GameStatePlaying : public GameState
{

public: 
	virtual void Draw();
	virtual void HandleInput();
	virtual void Update();
	//virtual void fixedUpdate(); 

	GameStatePlaying(Game* game);
};

