#include "GameStatePlaying.hpp"

#include "../TextureManager.hpp"

void GameStatePlaying::Draw()
{
	//Score draw
	
	//Board draw 
	game->Ui->draw(game->window);
	game->board->draw(); 
}

void GameStatePlaying::HandleInput()
{
	sf::Event event; 
	while (game->window.pollEvent(event))
	{
		//Shape Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))      {}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))     {}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  game->board->currentShape->move(sh::dir::down); 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  game->board->currentShape->move(sh::dir::left); 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) game->board->currentShape->move(sh::dir::right);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) game->window.close();
	}
}

void GameStatePlaying::Update()
{
	game->board->Update(); 
	game->Ui->Update(); 
}



GameStatePlaying::GameStatePlaying(Game* game) {
	this->game = game;
	if (this->game->board != nullptr) {
		delete(this->game->board); 
	}
	this->game->board = new Board(this->game);
}