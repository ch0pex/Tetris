#pragma once
#include "GameState.hpp"
#include "../Shapes/Shape.hpp"
#include "../Board.hpp"
#include <list>
#include <iostream>

class GameStatePlaying : public GameState
{

public: 
	void Draw() override;
	void HandleInput() override;
	void Update() override;

	GameStatePlaying(Game* game);
};

