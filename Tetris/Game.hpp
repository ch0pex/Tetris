#pragma once
#include <iostream>
#include "SFML-2.5.1/include/SFMl/Graphics.hpp"
#include "GameState.hpp"
#include "Board.hpp"
#include "TextureManager.hpp"	


class GameState; 

class Game
{
private: 
	void loadTextures();
public:
	TextureManager texMng; 
	sf::RenderWindow window; 
	sf::Font font; 

	GameState* gameState;
	Board* board;
	void gameLoop();
	Game();
	~Game();

};

