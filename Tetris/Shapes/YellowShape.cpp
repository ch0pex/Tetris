#include "YellowShape.hpp"

sh::YellowShape::YellowShape(sf::Texture* texture)
{
	position = sf::Vector2f(600, 300);
	
	struct sh::ShapeComponent comp1; 
	struct sh::ShapeComponent comp2;
	struct sh::ShapeComponent comp3;
	struct sh::ShapeComponent comp4;

	comp1.offset = sf::Vector2f(0, 0); 
	comp2.offset = sf::Vector2f(); 
	comp3.offset = sf::Vector2f(); 
	comp4.offset = sf::Vector2f(); 
}
