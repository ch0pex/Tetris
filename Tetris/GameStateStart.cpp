#include "GameStateStart.hpp"
#include "GameStatePlaying.hpp"
#include "Shapes/shape.hpp"

void GameStateStart::Draw() { 
	game->board->draw(game->window); 
}


void GameStateStart::HandleInput() {
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		if (sf::Event::KeyPressed){
			if (event.key.code == sf::Keyboard::Escape)
				game->window.close();
			else if (event.key.code == sf::Keyboard::Down) {
				currentOption = 0;
				start.setFillColor(sf::Color::White); 
				exit.setFillColor(sf::Color::Yellow);
			}	
			else if (event.key.code == sf::Keyboard::Up) {
				currentOption = 1;
				start.setFillColor(sf::Color::Yellow);
				exit.setFillColor(sf::Color::White);
			}
				
			else if (event.key.code == sf::Keyboard::Enter) {
				if (currentOption) game->gameState = new GameStatePlaying(game);
				else game->window.close(); 
			}
		}
	}
}


void GameStateStart::Update() {
	
	return; 
}




 
GameStateStart::GameStateStart(Game* game) {
	this->game = game;
	currentOption = 1;
}


