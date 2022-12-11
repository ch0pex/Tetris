#include "GameStatePlaying.hpp"

#include "TextureManager.hpp"

void GameStatePlaying::Draw()
{
	//Score draw
	
	//Board draw 
	game->board->draw(game->window);
	shapes.front().draw();
	shapes.back().draw(); 
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
			case sf::Keyboard::Down: shapes.back().move(sh::dir::right); break; // Faster 
			case sf::Keyboard::Left: shapes.back().move(sh::dir::right); break; // Left 
			case sf::Keyboard::Right: shapes.back().move(sh::dir::right);break; // Right
			case sf::Keyboard::Escape: game->window.close();  // alt + f4
			default: break;
			}
		}
	}
}

void GameStatePlaying::Update()
{
	// if current shape is in conctact pop 
	if (shapes.back().inContact) {
		shapes.pop_back(); 
		shapes.push_front(this->game->shMng.getRandomShape());
	}
	shapes.back().move(sh::dir::down); 

}



GameStatePlaying::GameStatePlaying(Game* game) {
	this->game = game;
	shapes.push_front(this->game->shMng.getRandomShape()); 
	shapes.push_front(this->game->shMng.getRandomShape());
}