#include "Board.hpp"
#include "Shapes/Shapes.hpp"
#include <thread>




sh::Shape* Board::genNextShape() {
	//int choice = 7; 
	srand(time(NULL));
	int choice = rand() % 8;
	switch (choice) {
	case 1:
		return new sh::CianShape(game->texMng.getTextureRef("cian"), sf::Vector2f(550, 150));
	case 2:
		return new sh::YellowShape(game->texMng.getTextureRef("yellow"), sf::Vector2f(550, 150));
	case 3: 
		return new sh::PurpleShape(game->texMng.getTextureRef("purple"), sf::Vector2f(550, 150)); 
	case 4: 
		return new sh::OrangeShape(game->texMng.getTextureRef("orange"), sf::Vector2f(550, 150));
	case 5: 
		return  new sh::BlueShape(game->texMng.getTextureRef("blue"), sf::Vector2f(550, 150)); 
	case 6: 
		return new sh::GreenShape(game->texMng.getTextureRef("green"), sf::Vector2f(550, 150));
	case 7: 
		return new sh::RedShape(game->texMng.getTextureRef("red"), sf::Vector2f(559, 150)); 
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
	std::chrono::microseconds time(700*1000);
	std::chrono::microseconds speedUp(300);
	std::chrono::microseconds maxSpeed(50*1000);
	int x = 0;
	if (currentShape == nullptr) return; 
	while (1) {
		if(!currentShape->contact[sh::dir::down])
			currentShape->move(sh::dir::down); 
		std::this_thread::sleep_for(time);
	}

}

bool Board::checkPlaced()
{
 
	std::cout << checkTicks << std::endl; 
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
	if (checkPlaced()) {
		shapeToGrid(currentShape);
		currentShape = nextShape;
		currentShape->setPos(sf::Vector2f(250, 0));
		nextShape = genNextShape();
	
	}
	currentShape->Update(grid);
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
	nextShape->draw(game->window);
	if (extraShape) {
		extraShape->setPos(sf::Vector2f(600, 800)); 
		std::cout << extraShape->getPos().x << ", " << extraShape->getPos().y << std::endl;
		extraShape->draw(game->window);
	}
}

void Board::swapShapes()
{

	for (auto* component : (extraShape != nullptr ? extraShape->getComponents() : nextShape->getComponents())) {
		if (grid[((int)currentShape->position.x + (int)component->offset.x) / 50][((int)currentShape->position.y + (int)component->offset.y) / 50] != nullptr)
			return;
	}
	if (extraShape == nullptr) {
		extraShape = currentShape;
		currentShape = nextShape;
		currentShape->setPos(extraShape->getPos());
		extraShape->position = sf::Vector2f(600, 800);
		nextShape = genNextShape();
	}
	else {
		sh::Shape* aux;
		extraShape->setPos(currentShape->getPos());
		aux = currentShape;
		aux->setPos(aux->extraPos);
		currentShape = extraShape;
		extraShape = aux;
	}
	



}


Board::Board(Game* game) {
	extraShape = nullptr; 
	this->game = game; 
 	nextShape = genNextShape(); 
	currentShape = genNextShape(); 
	currentShape->setPos(sf::Vector2f(250, 0)); 
	//thread with gravity func
	new std::thread(&Board::gravity, this);
	checkTicks = 0; 
	//new std::thread(&Board::checkPlaced, this);

}
	
