#include "State.hpp"

State::State(sf::RenderWindow& window, std::stack<State*>& states){
    this->window = &window;
    this->states = &states;
    //Dimensions
    this->width = window.getSize().x;
    this->height = window.getSize().y;

    //Background
    background = new sf::RectangleShape(sf::Vector2f(this->width, this->height));
    background->setFillColor(sf::Color(21, 30, 61));
    
    //Fonts
    initFonts();
}

State::~State(){
    delete background;
    delete titleFont;
}

void State::initFonts(){
    titleFont = new sf::Font();
    titleFont->loadFromFile("Fonts/Roboto-Bold.ttf");
}