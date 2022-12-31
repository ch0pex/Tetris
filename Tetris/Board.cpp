#include "Board.hpp"
#include "Shapes/Shapes.hpp"
#include <thread>




sh::Shape* Board::genNextShape() {
	srand(time(NULL));
	int choice = rand() % 3;
	std::cout << choice << std::endl;
	switch (choice) {
	case 1:
		return new sh::CianShape(game->texMng.getTextureRef("cian"), sf::Vector2f(550, 150));
	case 2:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));
	}
	return new sh::CianShape(game->texMng.getTextureRef("cian"), sf::Vector2f(550, 150));

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
	std::chrono::microseconds time(700*1000);
	std::chrono::microseconds speedUp(300);
	std::chrono::microseconds maxSpeed(50*1000);
	int x = 0; 
	while (1) {
		if(!currentShape->contact[sh::dir::down])
			currentShape->move(sh::dir::down); 
		std::this_thread::sleep_for(time);
	}

}

void Board::checkPlaced()
{
	int ticks = 0; 
	while (1) {
		if (!currentShape->contact[sh::dir::down]) ticks = 0;
		else ticks++; 
		if(ticks == 2) 
		{
			shapeToGrid(currentShape);
			currentShape = nextShape;
			currentShape->initPos(); 
			nextShape = genNextShape();
			ticks = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
	}
}


void Board::deleteRow(int y) {
	for (size_t x = 0; x < 10; x++)
	{
		grid[x][y] = nullptr;
	}
	for (size_t row = y; row > 0; --row)
	{
		for(size_t cell = 0; cell < 10; cell++)
			if (grid[cell][row] != nullptr) {
				grid[cell][row]->sprite.setPosition(grid[cell][row]->sprite.getPosition().x, grid[cell][row]->sprite.getPosition().y + 50);
				grid[cell][row + 1] = grid[cell][row];
				grid[cell][row] = nullptr;
			}
			
	}
}


void Board::Update()
{
	std::vector<int> rows;
	
	for (size_t y = 0; y < 20; y++)
	{
		bool full = true; 
		for (size_t x = 0; x < 10; x++)
		{
			if (grid[x][y] == nullptr) {
				full = false;
				break;
			}
		}
		if (full) rows.push_back(y);
	}
	if (rows.size()) {
		for (int row : rows)
			deleteRow(row);
	}

	currentShape->Update(grid);
	std::cout << currentShape->getPos().x << ", " << currentShape->getPos().y << std::endl;
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
	//thread with gravity func
	new std::thread(&Board::gravity, this);
	new std::thread(&Board::checkPlaced, this);

}
	
