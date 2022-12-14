#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"

namespace sh{

	enum dir {
		right = 0,
		left,
		down,
	};

	struct ShapeComponent
	{
		sf::Sprite sprite;
		sf::Vector2f offset;
	};

	

	class Shape
	{
	protected:
		std::vector<ShapeComponent> sprites;
		sf::Vector2f position; 
		sf::Texture texture; 
		
	public:
		void draw(sf::RenderWindow& window);
		void Update(); 
		bool inContact; 
		virtual void rotateShape();
		void move(enum dir);
	};

	



}
