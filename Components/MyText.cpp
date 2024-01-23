#include "MyText.hpp"


MyText::MyText(std::string_view content, sf::Font& font, 
                unsigned int weight, sf::Color color, sf::Vector2f position){
    this->weight = weight;
    this->position = position;
    this->content = content;
    this->color = color;  
    this->font = &font;  
    text =  sf::Text();
    text.setCharacterSize(weight);
    text.setString(this->content);
    text.setFillColor(this->color);
    text.setFont(*this->font);

    sf::FloatRect textRec = text.getGlobalBounds();
    text.setOrigin(sf::Vector2f(textRec.left + textRec.width/2.0f, 
                                textRec.top + textRec.height/2.0f));
    text.setPosition(this->position);
}

MyText::~MyText(){
}

void MyText::update(float& dt){

}

void MyText::render(sf::RenderTarget& target){
    target.draw(text);
}

