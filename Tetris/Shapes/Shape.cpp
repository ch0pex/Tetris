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
		if(!contact[sh::dir::right] && _position.x <= _limits[_rotation].at(1) - 50)
			_position += sf::Vector2f(50, 0);
		break; 
	case left:
		if (!contact[sh::dir::left] && _position.x >= _limits[_rotation].at(0) + 50)
			_position += sf::Vector2f(-50, 0) ;
		break;
	case down: 
		if(!contact[sh::dir::down] )
			_position += sf::Vector2f(0, 50);
		break;
	case up: 
		_position += sf::Vector2f(0, -50); 
		break;
	default:
		break;
	}
}


void sh::Shape::draw(sf::RenderWindow& window) 
{
	
	for (auto* component : _components) {
		if (component == nullptr) continue; 
		window.draw(component->sprite);
	}
}


void sh::Shape::Update(sh::ShapeComponent* grid[10][20])
 {
	if (placed) return; 
	if (!_components.size()) {
		delete(this); 
		return;
	};
	int x = _components.at(0)->offset.x + _position.x;
	int y = _components.at(0)->offset.y + _position.y;
	//std::cout << x / 50 << ", " << y / 50 << std::endl;
	//std::cout << contact[sh::dir::down] << std::endl;
	//std::cout << contact[sh::dir::left] << std::endl;
	//std::cout << contact[sh::dir::right] << std::endl;
	contact[sh::dir::down] = false; 
	contact[sh::dir::left] = false; 
	contact[sh::dir::right] = false; 
	for (auto* component : _components) {
		if (component == nullptr) continue; 
		component->checkCollision(_position, grid, contact);
		component->sprite.setPosition(_position + component->offset);
	}
}


std::vector<sh::ShapeComponent*> sh::Shape::getComponents() {
	return _components;
}


sf::Vector2f sh::Shape::getPos() 
{
	return _position; 
}


void sh::Shape::setPos(sf::Vector2f pos)
{
	_position = pos; 
	for (auto* component : _components) {
		component->sprite.setPosition(_position + component->offset); 
	}
}


sh::Shape::Shape() {
	_rotation = 0;
	placed = false;
	contact[sh::dir::down] = false;
	contact[sh::dir::left] = false;
	contact[sh::dir::right] = false;

}
