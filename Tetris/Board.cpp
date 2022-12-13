#include "Board.hpp"
#include "Shapes/Shapes.hpp"




sh::Shape* Board::genNextShape() {
	size_t choice = rand() % 6;
	switch (choice) {
	case 0:
		return new sh::BlueShape(game->texMng.getTextureRef("blue"));
	case 1:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"));
	}

}


void Board::Update()
{

}

void Board::draw()
{
	
}

Board::Board(Game* game) {
	this->game = game; 
}
