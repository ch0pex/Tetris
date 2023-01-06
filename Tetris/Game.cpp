#include "game.hpp"
#include "States/GameStateStart.hpp"
#include <Windows.h>
void Game::loadTextures()
{
	/*texture.loadFromFile("Assets/blue.png");*/
	texMng.loadTexture("blue", "Assets/blue.png");
	texMng.loadTexture("yellow", "Assets/yellow.png");
	texMng.loadTexture("orange", "Assets/orange.png");
	texMng.loadTexture("green",  "Assets/green.png");
	texMng.loadTexture("purple", "Assets/purple.png");
	texMng.loadTexture("cian",   "Assets/cian.png");

}

void Game::gameLoop() {

	while (window.isOpen())
	{
		gameState->HandleInput(); 		   // Handle input 
		gameState->Update();               // GameState Update 
		window.clear(sf::Color::Black);    // clear buffer 
		gameState->Draw();                 // draw 
		window.display(); 
		//Sleep(60); // when set Frame limit not works 
		// display
	}
}


Game::Game()
{	 
	loadTextures(); 
	window.setMouseCursorVisible(false); 
	Ui = new UserInterface();
	gameState = new GameStateStart(this);
	window.create(sf::VideoMode(800, 1000), "Tetris", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(1); 
}


Game::~Game()
{
	return; 
}

