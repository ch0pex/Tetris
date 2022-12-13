#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include "../game.hpp"
#include "GameState.hpp"


class GameStateStart : public GameState
{
private: 

	bool currentOption; 
public: 
	virtual void Draw();  
	virtual void HandleInput(); 
	virtual void Update(); 
	GameStateStart(Game* game);
};

