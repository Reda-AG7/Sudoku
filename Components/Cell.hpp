#ifndef __CELL__H
#define __CELL__H
#include "SFML/Graphics.hpp"

class Cell{
    private:
        sf::RectangleShape* cell;
        unsigned sideLength;
        sf::Vector2f position;
        char charValue;
        short intValue;
        bool status;
        sf::Color constantColor, mutableColor, hoverColor;
    public:
        Cell(unsigned&, sf::Vector2f);
        ~Cell();
        void update(float&, sf::Vector2f&);
        void render(sf::RenderTarget&);
        bool getStatus() const;
        void setValue(char);
};

#endif