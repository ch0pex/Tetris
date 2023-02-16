#include "GameStateOver.hpp"

void GameStateOver::Draw()
{
	game->Ui->draw(game->window);
}

void GameStateOver::HandleInput()
{
	sf::Event event;
	while (game->window.pollEvent(event)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			game->Ui->state = UiState::start;
			game->gameState = new GameStateStart(game);
		}
	}
}

void GameStateOver::Update()
{
	return;
}

GameStateOver::GameStateOver(Game* game) {
	this->game = game;
}