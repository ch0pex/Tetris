#include "PurpleShape.hpp"
#include <iostream>

sh::PurpleShape::PurpleShape(sf::Texture* texture, sf::Vector2f position)   
{

	_limits[0].push_back(0);
	_limits[0].push_back(400);
	_limits[0].push_back(900);
	_limits[1].push_back(0);
	_limits[1].push_back(400); 
	_limits[1].push_back(950);
	_limits[2].push_back(50); 
	_limits[2].push_back(450); 
	_limits[2].push_back(950);
	_limits[3].push_back(0);
	_limits[3].push_back(400); 
	_limits[3].push_back(1000);

	_position = position; 
	extraPos = sf::Vector2f(550, 775); 

	sh::ShapeComponent* comp1 = new sh::ShapeComponent();
	sh::ShapeComponent* comp2 = new sh::ShapeComponent();
	sh::ShapeComponent* comp3 = new sh::ShapeComponent();
	sh::ShapeComponent* comp4 = new sh::ShapeComponent();

	comp1->offset = _offsets[_rotation][0];
	comp3->offset = _offsets[_rotation][1];
	comp4->offset = _offsets[_rotation][2];
	comp2->offset = _offsets[_rotation][3];

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


void sh::PurpleShape::rotate(sh::ShapeComponent* grid[10][20]) 
{
	if (_rotation == 0  && _position.x == 0) return; 
	if (_rotation == 2 && _position.x == 450) return;
	_rotation = (_rotation + 1) % 4;
	for (sf::Vector2f offset : _offsets[_rotation]) {
		if (_position.y + offset.y > _limits[_rotation].at(2)) {
			_rotation -= 1; 
			return; 
		}
			

		if (grid[((int)_position.x + (int)offset.x) / 50][((int)_position.y + (int)offset.y) / 50] != nullptr)
		{
			_rotation -= 1; 
			return; 
		}
	}

	
	
	_components[0]->offset = _offsets[_rotation][0];
	_components[1]->offset = _offsets[_rotation][1];
	_components[2]->offset = _offsets[_rotation][2];
	_components[3]->offset = _offsets[_rotation][3];
 
	

	sf::Vector2f position0 = _components[0]->offset + _position;
	sf::Vector2f position1 = _components[1]->offset + _position;
	sf::Vector2f position2 = _components[2]->offset + _position;
	sf::Vector2f position3 = _components[3]->offset + _position;


	_components[0]->sprite.setPosition(position0);
	_components[1]->sprite.setPosition(position1);
	_components[2]->sprite.setPosition(position2);
	_components[3]->sprite.setPosition(position3);
	
}