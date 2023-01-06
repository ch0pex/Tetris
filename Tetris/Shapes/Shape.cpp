#include "Shape.hpp"
#include <iostream>


void sh::ShapeComponent::checkCollision(sf::Vector2f position, sh::ShapeComponent* grid[10][20], std::map<sh::dir,bool>& contacts)
{
	int x = offset.x + position.x; 
	int y = offset.y + position.y;
	if (grid[x/50][y/50 + 1] != nullptr || y == 950) contacts[sh::dir::down] = true;
	if (grid[x / 50 - 1][y / 50] != nullptr) contacts[sh::dir::left] = true;
	if (grid[x / 50 + 1][y / 50] != nullptr) contacts[sh::dir::right] = true;
	
}





void sh::Shape::move(enum sh::dir direction)
{
	switch (direction)
	{
	case right:
		if(!contact[sh::dir::right] && position.x <= limits[rotation].at(1) - 50)
			position += sf::Vector2f(50, 0);
		break; 
	case left:
		if (!contact[sh::dir::left] && position.x >= limits[rotation].at(0) + 50)
			position += sf::Vector2f(-50, 0) ;
		break;
	case down: 
		if(!contact[sh::dir::down] )
			position += sf::Vector2f(0, 50);
		break;
	case up: 
		position += sf::Vector2f(0, -50); 
		break;
	default:
		break;
	}
}


void sh::Shape::draw(sf::RenderWindow& window)
{
	for (auto* component : components) {
		window.draw(component->sprite);
	}
}


void sh::Shape::Update(sh::ShapeComponent* grid[10][20])
 {
	if (!components.size()) return; 
	int x = components.at(0)->offset.x + position.x;
	int y = components.at(0)->offset.y + position.y;
	//std::cout << x / 50 << ", " << y / 50 << std::endl;
	//std::cout << contact[sh::dir::down] << std::endl;
	//std::cout << contact[sh::dir::left] << std::endl;
	//std::cout << contact[sh::dir::right] << std::endl;
	contact[sh::dir::down] = false; 
	contact[sh::dir::left] = false; 
	contact[sh::dir::right] = false; 
	for (auto* component : components) {
		component->checkCollision(position, grid, contact);
		component->sprite.setPosition(position + component->offset);
	}
}


std::vector<sh::ShapeComponent*> sh::Shape::getComponents() {
	return components;
}


sf::Vector2f sh::Shape::getPos() 
{
	return position; 
}


void sh::Shape::initPos()
{
	position = sf::Vector2f(250, 0); 
}


sh::Shape::Shape() {
	rotation = 0; 
	placed = false; 
	contact[sh::dir::down] = false; 
	contact[sh::dir::left] = false; 
	contact[sh::dir::right] = false; 
	
}