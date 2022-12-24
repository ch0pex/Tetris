#include "GameStateStart.hpp"
#include "GameStatePlaying.hpp"
#include "../Shapes/shape.hpp"

void GameStateStart::Draw() { 
	game->Ui->draw(game->window); 
}


void GameStateStart::HandleInput() {
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			game->Ui->setOption(0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			game->Ui->setOption(1);
		}

		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
			if (game->Ui->getOption()) {
				game->Ui->state = UiState::playing; 
				game->gameState = new GameStatePlaying(game);
			}
			else game->window.close();
		}
		
	}
}


void GameStateStart::Update() {
	
	return; 
}


 
GameStateStart::GameStateStart(Game* game) {
	std::cout << "holastart" << std::endl;
	this->game = game;
	currentOption = 1;
}


