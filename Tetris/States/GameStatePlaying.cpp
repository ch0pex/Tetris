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
	int eventCount = 0; 
	while (game->window.pollEvent(event))
	{
		eventCount += 1; 
		if (eventCount > 1) return;
		std::cout << eventCount << std::endl; 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) game->window.close();
		//Shape Movement
		if (game->board->currentShape == nullptr) continue; 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  {}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	  {}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !game->board->currentShape->contact[sh::dir::down]) {
			std::cout << "pabajo" << std::endl; 
			game->board->currentShape->move(sh::dir::down);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !game->board->currentShape->contact[sh::dir::left]) {
			game->board->currentShape->move(sh::dir::left);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !game->board->currentShape->contact[sh::dir::right]) {
			game->board->currentShape->move(sh::dir::right);
		}
		
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