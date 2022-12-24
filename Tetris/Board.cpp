#include "Board.hpp"
#include "Shapes/Shapes.hpp"




sh::Shape* Board::genNextShape() {
	int choice = rand() % 2;
	switch (choice) {
	case 0:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));
	case 1:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));
	}
	return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));

}


void Board::shapeToGrid(sh::Shape* currentShape) 
{
	int x; 
	int y; 
	for (sh::ShapeComponent* component : currentShape->getComponents()) {
		x = (component->offset.x + currentShape->getPos().x) / 50; 
		y = (component->offset.y + currentShape->getPos().y) / 50;
		grid[x][y] = component; 
	}
	delete(currentShape); 
} 


void Board::gravity() {
	std::chrono::milliseconds time(500);
	std::chrono::milliseconds speedUp(50);
	std::chrono::milliseconds maxSpeed(50);

	while (true) {
		if (!currentShape->inContact)
			currentShape->move(sh::down); 
		std::this_thread::sleep_for(time);
		if (time > maxSpeed * 2) time -= speedUp; 

	}

}


void Board::Update()
{
	std::cout << currentShape->inContact << std::endl; 
	if (currentShape->inContact) {
		shapeToGrid(currentShape);
		currentShape = nextShape;
		currentShape->initPos();
		nextShape = genNextShape();
	}
	currentShape->Update(grid);
}


void Board::draw()
{
	for (auto& row : grid) {
		for (auto& block : row) {
			if(block != nullptr)
			game->window.draw(block->sprite); 
		}	 
	}
	currentShape->draw(game->window);
	nextShape->draw(game->window);
}


Board::Board(Game* game) {
	this->game = game; 
	nextShape = genNextShape(); 
	currentShape = genNextShape(); 
	currentShape->initPos(); 	
	fixedUpdate = new std::thread([this] {gravity();});
}
