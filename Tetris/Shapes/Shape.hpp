#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"

namespace sh{
	typedef struct {
		sf::Vector2i offset;
		sf::Sprite sprite;
	} ShapeComponent;

	enum dir {
		right = 0,
		left,
		down,
	};

	class Shape
	{
	private:
		std::vector<ShapeComponent> sprites;
		sf::Vector2f position; 
		
	public:
		void draw(); 
		void Update(); 
		bool inContact; 
		virtual void rotateShape();
		void move(enum dir);
	};

	

	class ShapeComponent
	{
	private: 
		sf::Sprite sprite; 
		sf::Vector2f offset; 
	};

}
