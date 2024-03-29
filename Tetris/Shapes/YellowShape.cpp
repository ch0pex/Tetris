#include "YellowShape.hpp"


sh::YellowShape::YellowShape(sf::Texture* texture, sf::Vector2f position) : Shape()
{ 
	_position = position; 
	extraPos = sf::Vector2f(525, 725); 
	
	_limits[0].push_back(0); 
	_limits[0].push_back(400);
	sh::ShapeComponent* comp1 = new sh::ShapeComponent();
	sh::ShapeComponent* comp2 = new sh::ShapeComponent();
	sh::ShapeComponent* comp3 = new sh::ShapeComponent();
	sh::ShapeComponent* comp4 = new sh::ShapeComponent();
	
	comp1->offset = sf::Vector2f(0,0); 
	comp2->offset = sf::Vector2f(50,0); 
	comp3->offset = sf::Vector2f(0,50); 
	comp4->offset = sf::Vector2f(50,50); 
	
	sf::Vector2f scale = sf::Vector2f(0.125f, 0.125f);
	comp1->sprite.setScale(scale);
	comp2->sprite.setScale(scale);
	comp3->sprite.setScale(scale);
	comp4->sprite.setScale(scale);
	 
	comp1->sprite.setTexture(*texture); 
	comp2->sprite.setTexture(*texture); 
	comp3->sprite.setTexture(*texture); 
	comp4->sprite.setTexture(*texture); 

	comp1->sprite.setPosition(comp1->offset + _position);
	comp2->sprite.setPosition(comp2->offset + _position);
	comp3->sprite.setPosition(comp3->offset + _position);
	comp4->sprite.setPosition(comp4->offset + _position);

	_components.push_back(comp1); 
	_components.push_back(comp2);
	_components.push_back(comp3); 
	_components.push_back(comp4); 

}

void sh::YellowShape::rotate(sh::ShapeComponent* grid[10][20])
{
	return; //YellowShape ain't rotat
}



