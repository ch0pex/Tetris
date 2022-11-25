#include "GameStateStart.hpp"
#include "GameStatePlaying.hpp"


void GameStateStart::Draw() {
	game->window.draw(title); 
	game->window.draw(start); 
	game->window.draw(exit); 
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
	title.setCharacterSize(70); 
	title.setFont(game->font); 
	title.setString("Tetris"); 
	title.setPosition(sf::Vector2f(560, 400)); 
	start.setCharacterSize(30); 
	start.setFont(game->font);
	start.setFillColor(sf::Color::Yellow); 
	start.setString("Start"); 
	start.setPosition(sf::Vector2f(605, 510)); 
	exit.setCharacterSize(30);
	exit.setFont(game->font);
	exit.setString("Exit");
	exit.setPosition(sf::Vector2f(615, 560));
}


