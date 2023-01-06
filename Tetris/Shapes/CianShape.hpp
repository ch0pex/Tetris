#pragma once
#include "Shape.hpp"
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"	

namespace sh {
    class CianShape : public Shape
    {
    private:
        sf::Vector2f offsetsVer[4] = { sf::Vector2f(0,0), sf::Vector2f(0, 50), sf::Vector2f(0, 100), sf::Vector2f(0, 150)  };
        sf::Vector2f offsetsHor[4] = { sf::Vector2f(0, 0), sf::Vector2f(50, 0), sf::Vector2f(100, 0), sf::Vector2f(150, 0) };
    public: 
        CianShape(sf::Texture* texture, sf::Vector2f position);
        void rotate(sh::ShapeComponent* grid[10][20]) override;
    };
}


