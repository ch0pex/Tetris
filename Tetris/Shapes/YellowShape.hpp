#pragma once
#include "Shape.hpp"
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"	
namespace sh {
	class YellowShape : public Shape
	{
		
	public:
		void Update(); 
		YellowShape(sf::Texture* texture, sf::Vector2f position);
	};


}
