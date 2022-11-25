#pragma once
#include "GameState.hpp"
#include "Board.hpp"

class GameStatePlaying : public GameState
{
public: 
	virtual void Draw();
	virtual void HandleInput();
	virtual void Update();
	GameStatePlaying(Game* game);
};

