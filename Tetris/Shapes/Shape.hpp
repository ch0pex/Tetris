#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <thread>

namespace sh{

	enum dir {
		right = 0,
		left,
		down,
		up
	};

	class ShapeComponent
	{
	public:
		ShapeComponent(); 
		sf::Sprite sprite;
		sf::Vector2f offset;
		void checkCollision(sf::Vector2f position, sh::ShapeComponent* grid[10][20],std::map<sh::dir,bool>& contacs);
	};


	class Shape
	{
	protected:
		std::vector<ShapeComponent*> components;
		sf::Vector2f position; 
		sf::Texture texture;
	
		Shape(); 
		
		
	public:
		void draw(sf::RenderWindow& window);
		void Update(sh::ShapeComponent* grid[10][20]);
		bool placed;
		std::map<sh::dir,bool> contact; 
		virtual void rotateShape();
		void initPos(); 
		void move(enum dir);
		std::vector<sh::ShapeComponent*> getComponents();
		sf::Vector2f getPos(); 
	};
}
