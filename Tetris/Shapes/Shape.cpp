#include "Shape.hpp"
#include <iostream>

sh::ShapeComponent::ShapeComponent()
{
}


sh::dir sh::ShapeComponent::checkCollision(sf::Vector2f position, sh::ShapeComponent* grid[10][20])
{
	int x = offset.x + position.x; 
	int y = offset.y + position.y;
	if (y == 950) return sh::dir::down;
	if (grid[x/50][y/50 + 1] != nullptr) return sh::dir::down;
	if (grid[x / 50 - 1][y / 50] != nullptr) return sh::dir::left; 
	if (grid[x / 50 + 1][y / 50] != nullptr) return sh::dir::right; 
	return sh::dir::up; 
}


void sh::Shape::move(enum sh::dir direction)
{
	switch (direction)
	{
	case right:
		if(position.x < 400 && !contact[sh::dir::right])
			position += sf::Vector2f(50, 0);
		break; 
	case left:
		if (position.x > 0 && !contact[sh::dir::left])
			position += sf::Vector2f(-50, 0);
		break;
	case down: 
		if (position.y < 900)
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
	contact[sh::dir::left] = false;
	contact[sh::dir::right] = false;
	for (auto* component : components) {
		sh::dir collision = component->checkCollision(position, grid); 
		switch (collision)
		{
		case sh::right:
			contact[sh::dir::right] = true; 
			break;
		case sh::left:
			contact[sh::dir::left] = true; 
			break;
		case sh::down:
			contact[sh::dir::down] = true; 
			break;
		default:
			break;
		}
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
	
	contact[sh::dir::down] = false; 
	contact[sh::dir::left] = false; 
	contact[sh::dir::right] = false; 
	
}