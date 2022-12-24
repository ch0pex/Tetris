#include "Shape.hpp"
#include <iostream>

sh::ShapeComponent::ShapeComponent()
{
}


bool sh::ShapeComponent::checkColision(sf::Vector2f position, sh::ShapeComponent* grid[10][20])
{
	int x = offset.x + position.x; 
	int y = offset.y + position.y;
	if (y == 950) return true;
	if (grid[x/50][y/50 + 1] != nullptr) return true;
	return false; 
}


void sh::Shape::move(enum sh::dir direction)
{
	switch (direction)
	{
	case right:
		if(position.x < 400)
			position += sf::Vector2f(50, 0);
		break; 
	case left:
		if (position.x > 0)
			position += sf::Vector2f(-50, 0);
		break;
	case down: 
		if (position.y < 900)
			position += sf::Vector2f(0, 50);
		break;
	case up: 
		position += sf::Vector2f(0, -50); 
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
	for (auto* component : components) {
		if (component->checkColision(position,grid))
			inContact = true; 
		component->sprite.setPosition(position + component->offset);
	}
}




void sh::Shape::rotateShape()
{
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
	
	inContact = false; 
	
}