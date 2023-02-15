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
		sf::Sprite sprite;
		sf::Vector2f offset;
		void checkCollision(sf::Vector2f position, sh::ShapeComponent* grid[10][20],std::map<sh::dir,bool>& contacs);
	};


	class Shape
	{
	protected:
		int _rotation; 
		sf::Vector2f _position; 
		std::map<int, std::vector<int>> _limits;
		std::vector<ShapeComponent*> _components;
		Shape(); 
		
		
	public:

		bool placed;
		sf::Vector2f extraPos; 
		std::map<sh::dir, bool> contact;

		std::vector<sh::ShapeComponent*> getComponents();
		sf::Vector2f getPos();
		void setPos(sf::Vector2f pos); 
		void draw(sf::RenderWindow& window);
		void move(enum dir);


		virtual void Update(sh::ShapeComponent* grid[10][20]);
		virtual void rotate(sh::ShapeComponent* grid[10][20]) = 0;
	};
}
