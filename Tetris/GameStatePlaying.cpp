#include "GameStatePlaying.hpp"


void GameStatePlaying::Draw()
{
	//Score draw
	
	//Board draw 
	game->board->draw(game->window); 
}

void GameStatePlaying::HandleInput()
{
	sf::Event event; 
	while (game->window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed: 
			game->window.close(); 
			break; 
		case sf::Event::KeyPressed: 
			switch (event.key.code)
			{
			case sf::Keyboard::Space:	break; // Rotate 
			case sf::Keyboard::Up:		break; // Teleport
			case sf::Keyboard::Down:	break; // Faster 
			case sf::Keyboard::Left:	break; // Left 
			case sf::Keyboard::Right:	break; // Right
			case sf::Keyboard::Escape: game->window.close();  // alt + f4
			default: break;
			}
		}
	}
}

void GameStatePlaying::Update()
{
	//Score Update 
	//Board Update 
}

GameStatePlaying::GameStatePlaying(Game* game) {
	this->game = game; 
}