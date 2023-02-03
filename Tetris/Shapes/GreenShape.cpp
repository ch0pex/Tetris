#include "GreenShape.hpp"
#include <iostream>

sh::GreenShape::GreenShape(sf::Texture* texture, sf::Vector2f position)
{

	limits[0].push_back(50);
	limits[0].push_back(450);
	limits[0].push_back(950);
	limits[1].push_back(50);
	limits[1].push_back(450);
	limits[1].push_back(950);



	position = sf::Vector2f(600, 300);

	sh::ShapeComponent* comp1 = new sh::ShapeComponent;
	sh::ShapeComponent* comp2 = new sh::ShapeComponent;
	sh::ShapeComponent* comp3 = new sh::ShapeComponent;
	sh::ShapeComponent* comp4 = new sh::ShapeComponent;

	comp1->offset = _offsets[rotation][0];
	comp3->offset = _offsets[rotation][1];
	comp4->offset = _offsets[rotation][2];
	comp2->offset = _offsets[rotation][3];

	sf::Vector2f scale = sf::Vector2f(0.125f, 0.125f);
	comp1->sprite.setScale(scale);
	comp2->sprite.setScale(scale);
	comp3->sprite.setScale(scale);
	comp4->sprite.setScale(scale);

	comp1->sprite.setTexture(*texture);
	comp2->sprite.setTexture(*texture);
	comp3->sprite.setTexture(*texture);
	comp4->sprite.setTexture(*texture);

	comp1->sprite.setPosition(comp1->offset + position);
	comp2->sprite.setPosition(comp2->offset + position);
	comp3->sprite.setPosition(comp3->offset + position);
	comp4->sprite.setPosition(comp4->offset + position);

	components.push_back(comp1);
	components.push_back(comp2);
	components.push_back(comp3);
	components.push_back(comp4);
	rotation = 0;
}


void sh::GreenShape::rotate(sh::ShapeComponent* grid[10][20])
{
	if (rotation == 1 && position.x == 450) return;

	rotation = (rotation + 1) % 2;
	for (sf::Vector2f offset : _offsets[rotation]) {
		if (position.y + offset.y > limits[rotation].at(2)) {
			rotation -= 1;
			return;
		}
		if (grid[((int)position.x + (int)offset.x) / 50][((int)position.y + (int)offset.y) / 50] != nullptr) {
			rotation -= 1;
			return;
		}

	}

	components[0]->offset = _offsets[rotation][0];
	components[1]->offset = _offsets[rotation][1];
	components[2]->offset = _offsets[rotation][2];
	components[3]->offset = _offsets[rotation][3];



	sf::Vector2f position0 = components[0]->offset + position;
	sf::Vector2f position1 = components[1]->offset + position;
	sf::Vector2f position2 = components[2]->offset + position;
	sf::Vector2f position3 = components[3]->offset + position;


	components[0]->sprite.setPosition(position0);
	components[1]->sprite.setPosition(position1);
	components[2]->sprite.setPosition(position2);
	components[3]->sprite.setPosition(position3);

}