#pragma once
#include "GameState.hpp"
#include "GameStateStart.hpp"

class GameStateOver : public GameState
{
public: 
	void Draw() override;
	void HandleInput() override;
	void Update() override;

	GameStateOver(Game* game);
};

