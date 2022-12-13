#pragma once
#include <iostream>
#include "SFML-2.5.1/include/SFMl/Graphics.hpp"
#include "States/GameState.hpp"
#include "UserInterface.hpp"
#include "TextureManager.hpp"	
#include "Board.hpp"


class GameState; 
class Board;

class Game
{
private: 
	void loadTextures();
public:
	TextureManager texMng;  
	sf::RenderWindow window; 
 
	Board* board;
	GameState* gameState;
	UserInterface* Ui;

	void gameLoop();

	Game();
	~Game();

};

