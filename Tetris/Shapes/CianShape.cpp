#include "CianShape.hpp"

sh::CianShape::CianShape(sf::Texture* texture, sf::Vector2f position)
{

	limits[0].first = 0; 
	limits[0].second = 950; 
	limits[1].first = 0; 
	limits[1].second = 800;
	rotation = 0; 


	position = sf::Vector2f(600, 300);

	sh::ShapeComponent* comp1 = new sh::ShapeComponent;
	sh::ShapeComponent* comp2 = new sh::ShapeComponent;
	sh::ShapeComponent* comp3 = new sh::ShapeComponent;
	sh::ShapeComponent* comp4 = new sh::ShapeComponent;
	
	comp1->offset = sf::Vector2f(0, 0);
	comp3->offset = sf::Vector2f(0, 50);
	comp4->offset = sf::Vector2f(0, 100);
	comp2->offset = sf::Vector2f(0, 150);

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

}


/*
bool checkPosition() {
	if (grid[(int)position.x / 50][(int)position.y / 50 + 1] != nullptr || (int) position.y == 950) return true; 
	if (grid[(int)position.x / 50 - 1][(int)position.y / 50] != nullptr) return true; 
	if (grid[(int)position.x / 50 + 1][(int)position.y / 50] != nullptr) return true; 
	return false; 
}
*/
void sh::CianShape::rotate() {
	if (rotation) {
		components[0]->offset = sf::Vector2f(0, 0);
		components[1]->offset = sf::Vector2f(0, 50);
		components[2]->offset = sf::Vector2f(0, 100);
		components[3]->offset = sf::Vector2f(0, 150);
	}
	else {
		components[0]->offset = sf::Vector2f(0, 0);
		components[1]->offset = sf::Vector2f(50, 0);
		components[2]->offset = sf::Vector2f(100, 0);
		components[3]->offset = sf::Vector2f(150, 0);
	}

	rotation = !rotation; 
	sf::Vector2f position0 = components[0]->offset + position;
	sf::Vector2f position1 = components[1]->offset + position;
	sf::Vector2f position2 = components[2]->offset + position;
	sf::Vector2f position3 = components[3]->offset + position;

	
	components[0]->sprite.setPosition(position0);
	components[1]->sprite.setPosition(position1);
	components[2]->sprite.setPosition(position2);
	components[3]->sprite.setPosition(position3);
	


}