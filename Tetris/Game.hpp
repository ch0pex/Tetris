#pragma once
#include <iostream>
#include "SFML-2.5.1/include/SFMl/Graphics.hpp"
#include "GameState.hpp"
#include "Board.hpp"
#include "Managers.hpp"	


class GameState; 


class Game
{
private: 
	void loadTextures();
public:
	mn::TextureManager texMng;  
	mn::ShapeManager shMng; 
	sf::RenderWindow window; 
 

	GameState* gameState;
	Board* board;

	void gameLoop();

	Game();
	~Game();

};

