#include "Cell.hpp"

Cell::Cell(unsigned& sideLength, sf::Vector2f position){
    this->sideLength = sideLength;
    this->position = position;
    this->status = true;
    cell = new sf::RectangleShape(sf::Vector2f(this->sideLength, this->sideLength));
    cell->setPosition(this->position);
    cell->setFillColor(sf::Color::White);
    cell->setOutlineColor(sf::Color::Black);
    cell->setOutlineThickness(1u);
    
    this->constantColor = sf::Color::Black;
    this->mutableColor = sf::Color(21, 30, 61);
    this->hoverColor = sf::Color(123, 134, 171);

    this->charValue = 'N';
    this->intValue = 0;
}

Cell::~Cell(){
    delete cell;
}

void Cell::update(float& dt, sf::Vector2f& mousePosition){
    if(cell->getGlobalBounds().contains(mousePosition)){
        cell->setFillColor(this->hoverColor);
    }
    else cell->setFillColor(sf::Color::White);
}

void Cell::render(sf::RenderTarget& target){
    target.draw(*cell);
}