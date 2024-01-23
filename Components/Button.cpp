#include "Button.hpp"

Button::Button(float width, float height,
                std::string_view content, sf::Font& font, 
                unsigned int weight, sf::Color color, sf::Vector2f position){
    
    this->width = width;
    this->height = height;
    this->position = position;

    this->pressed = false;
    this->idle = sf::Color(21, 30, 61);
    this->hover = sf::Color(38, 55, 117);

    text = new MyText(content, font, weight, color,position);
    rec.setSize(sf::Vector2f(this->width, this->height));

    rec.setOutlineThickness(1u);
    rec.setFillColor(sf::Color(21, 30, 61));
    rec.setOutlineColor(sf::Color::White);

    sf::FloatRect recRec = rec.getGlobalBounds();
    rec.setOrigin(sf::Vector2f(recRec.left + recRec.width/2.0f, 
                                recRec.top + recRec.height/2.0f));
    rec.setPosition(this->position);
}

Button::~Button(){
    delete text;
}

void Button::update(float& dt, sf::Vector2f mousePosition){
    if(rec.getGlobalBounds().contains(mousePosition)){
        rec.setFillColor(hover);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->pressed = true;
    }
    else rec.setFillColor(idle);
}

void Button::render(sf::RenderTarget& target){
    target.draw(rec);
    text->render(target);
}

bool Button::isPressed() const{
    return pressed;
}

void Button::setPressed(bool state){
    this->pressed = state;
}