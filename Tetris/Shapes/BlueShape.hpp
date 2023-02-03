#pragma once
#include "Shape.hpp"
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"	


namespace sh
{
	class BlueShape : public sh::Shape
	{
	private:
		sf::Vector2f _offsets[4][4] = {
			{ sf::Vector2f(0,-50), sf::Vector2f(0, 0), sf::Vector2f(-50, 0), sf::Vector2f(-100, 0)  },
			{ sf::Vector2f(50,0), sf::Vector2f(0, 0), sf::Vector2f(0, -50), sf::Vector2f(0, -100)},
			{ sf::Vector2f(0,50), sf::Vector2f(0, 0), sf::Vector2f(50,0), sf::Vector2f(100, 0) },
			{ sf::Vector2f(-50,0), sf::Vector2f(0, 0), sf::Vector2f(0, 50), sf::Vector2f(0, 100) } };

	public:
		BlueShape(sf::Texture* texture, sf::Vector2f position);
		void rotate(sh::ShapeComponent* grid[10][20]);
	};
}
