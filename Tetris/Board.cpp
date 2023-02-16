#include "Board.hpp"
#include "Shapes/Shapes.hpp"
#include <thread>




sh::Shape* Board::genNextShape() {
	//int choice = 7; 
	srand(time(NULL));
	int choice = rand() % 8;
	switch (choice) {
	case 1:
		return new sh::CianShape(game->texMng.getTextureRef("cian"), sf::Vector2f(575, 100));
	case 2:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));
	case 3: 
		return new sh::PurpleShape(game->texMng.getTextureRef("purple"), sf::Vector2f(550, 175));
	case 4: 
		return new sh::OrangeShape(game->texMng.getTextureRef("orange"), sf::Vector2f(525, 200));
	case 5: 
		return  new sh::BlueShape(game->texMng.getTextureRef("blue"), sf::Vector2f(625, 200));
	case 6: 
		return new sh::GreenShape(game->texMng.getTextureRef("green"), sf::Vector2f(575, 150));
	case 7: 
		return new sh::RedShape(game->texMng.getTextureRef("red"), sf::Vector2f(575, 175));
	}
	return new sh::CianShape(game->texMng.getTextureRef("cian"), sf::Vector2f(550, 150));

}


void Board::shapeToGrid(sh::Shape* currentShape) 
{
	int x; 
	int y; 
	for (sh::ShapeComponent* component : currentShape->getComponents()) {
		if (component == nullptr) continue; 
		x = (component->offset.x + currentShape->getPos().x) / 50; 
		y = (component->offset.y + currentShape->getPos().y) / 50;
		grid[x][y] = component; 
	}
 	delete(currentShape); 
} 


void Board::gravity() {


	std::chrono::microseconds maxSpeed(50*1000);
	int x = 0;
	if (currentShape == nullptr) return; 
	while (1) {
		if(!currentShape->contact[sh::dir::down])
			currentShape->move(sh::dir::down); 
		int factor = 500000 - _score * 100;
		std::chrono::microseconds time(factor > 5000 ? factor : 50000);
		std::cout << _score << std::endl;
		std::cout << factor << std::endl;
		std::this_thread::sleep_for(time);
	}

}

bool Board::checkPlaced()
{
	static int checkTicks = 0; 

	if (!currentShape->contact[sh::dir::down]) {
		checkTicks = 0;
		return false; 
	}
	else if (checkTicks > 50) {
		checkTicks = 0;
		return true;
	}
	else {
		checkTicks++;
		return false; 
	}


	
}


void Board::deleteRow(int y) {
	_score += 100;
	for (size_t x = 0; x < 10; x++)
	{
		grid[x][y] = nullptr;
	}
	for (size_t row = y; row > 0; row--)
	{
		for(size_t cell = 0; cell < 10; cell++)
			if (grid[cell][row] != nullptr) {
				grid[cell][row]->sprite.setPosition(grid[cell][row]->sprite.getPosition().x, grid[cell][row]->sprite.getPosition().y + 50);
				grid[cell][row + 1] = grid[cell][row];
				grid[cell][row] = nullptr;
			}
			
	}
}

int Board::checkGameOver()
{
	if (grid[5][0] != nullptr) return (-1); 
	if (grid[5][1] != nullptr) return (-1);
	if (grid[5][2] != nullptr) return (-1);
	return _score; 
}


int Board::Update()
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
	if (checkPlaced()) { 
		shapeToGrid(currentShape);
		currentShape = _nextShape;
		currentShape->setPos(sf::Vector2f(250,0));
		_nextShape = genNextShape();
	}
	currentShape->Update(grid);
	return checkGameOver(); 
	//std::cout << currentShape->getPos().x << ", " << currentShape->getPos().y << std::endl;
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
	_nextShape->draw(game->window);
	if (_extraShape) {
		_extraShape->setPos(sf::Vector2f(600, 800)); 
		std::cout << _extraShape->getPos().x << ", " << _extraShape->getPos().y << std::endl;
		_extraShape->draw(game->window);
	}
}

void Board::swapShapes()
{
	for (auto* component : (_extraShape != nullptr ? _extraShape->getComponents() : _nextShape->getComponents())) {
		if (grid[((int)currentShape->getPos().x + (int)component->offset.x) / 50][((int)currentShape->getPos().y + (int)component->offset.y) / 50] != nullptr)
			return;
	}
	if (_extraShape == nullptr) {
		_extraShape = currentShape;
		currentShape = _nextShape;
		currentShape->setPos(_extraShape->getPos());
		_extraShape->setPos(_extraShape->extraPos);
		_nextShape = genNextShape();
	}
	else {
		sh::Shape* aux;
		_extraShape->setPos(currentShape->getPos());
		aux = currentShape;
		aux->setPos(aux->extraPos);
		currentShape = _extraShape;
		_extraShape = aux;
	}
}


Board::Board(Game* game) {
	_extraShape = nullptr; 
	_score = 0;
	this->game = game; 
 	_nextShape = genNextShape(); 
	currentShape = genNextShape(); 
	currentShape->setPos(sf::Vector2f(250, 0)); 
	//thread with gravity func
	new std::thread(&Board::gravity, this);
	//new std::thread(&Board::checkPlaced, this);

}
	
