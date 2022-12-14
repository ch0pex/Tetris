#include "Board.hpp"
#include "Shapes/Shapes.hpp"




sh::Shape* Board::genNextShape() {
	int choice = rand() % 2;
	switch (choice) {
	case 0:
		return new sh::BlueShape(game->texMng.getTextureRef("blue"));
	case 1:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"));
	}
	return new sh::BlueShape(game->texMng.getTextureRef("blue")); 

}


void Board::Update()
{
	//currentShape->Update(); 
	
	//if(currentShape.state == placed)
		//currentShape -> grid
		//currentShape = nextShape();
		//nextShape = genNextShape();
}

void Board::draw()
{
	currentShape->draw(game->window);
	nextShape->draw(game->window);
	/*for (auto& row : grid) {
		for (auto& block : row) {
			game->window.draw(block->sprite); 
		}	 
	}*/
}

Board::Board(Game* game) {
	this->game = game; 
	nextShape = new sh::YellowShape(game->texMng.getTextureRef("yellow"));
	currentShape = new sh::YellowShape(game->texMng.getTextureRef("yellow"));
}
