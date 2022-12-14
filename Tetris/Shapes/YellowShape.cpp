#include "YellowShape.hpp"


sh::YellowShape::YellowShape(sf::Texture* texture, sf::Vector2f position)
{
	//position = sf::Vector2f(550, 150);
	
	struct sh::ShapeComponent comp1; 
	struct sh::ShapeComponent comp2;
	struct sh::ShapeComponent comp3;
	struct sh::ShapeComponent comp4;

	comp1.offset = sf::Vector2f(0,0); 
	comp2.offset = sf::Vector2f(25,0); 
	comp3.offset = sf::Vector2f(0,25); 
	comp4.offset = sf::Vector2f(25,25); 
	
	sf::Vector2f scale = sf::Vector2f(0.0625f, 0.0625f);
	comp1.sprite.setScale(scale);
	comp2.sprite.setScale(scale);
	comp3.sprite.setScale(scale);
	comp4.sprite.setScale(scale);

	comp1.sprite.setTexture(*texture); 
	comp2.sprite.setTexture(*texture); 
	comp3.sprite.setTexture(*texture); 
	comp4.sprite.setTexture(*texture); 

	comp1.sprite.setPosition(comp1.offset + position);
	comp2.sprite.setPosition(comp2.offset + position);
	comp3.sprite.setPosition(comp3.offset + position);
	comp4.sprite.setPosition(comp4.offset + position);

	sprites.push_back(comp1); 
	sprites.push_back(comp2);
	sprites.push_back(comp3); 
	sprites.push_back(comp4); 

}


