#include "Shape.hpp"

void sh::Shape::move(enum sh::dir direction)
{
	switch (direction)
	{
	case right: 
		position += sf::Vector2f(1, 0); 
	case left: 
		position += sf::Vector2f(-1, 0); 
	case down: 
		position += sf::Vector2f(0, 1); 
	default:
		break;
	}
}

void sh::Shape::draw()
{
}

void sh::Shape::Update() {

}

void sh::Shape::rotateShape()
{
}
