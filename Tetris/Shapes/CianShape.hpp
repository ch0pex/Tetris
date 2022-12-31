#pragma once
#include "Shape.hpp"
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"	

namespace sh {
    class CianShape : public Shape
    {

    public: 
        CianShape(sf::Texture* texture, sf::Vector2f position);
        void rotate(sh::ShapeComponent* grid[10][20]) override;
    };
}


