#ifndef __MY_TEXT__H
#define __MY_TEXT__H
#include "SFML/Graphics.hpp"
#include<iostream>
#include<string_view>

class MyText{
    private:
        sf::Text text;
        std::string content;
        sf::Font* font;
        sf::Color color;
        unsigned int weight;
        sf::Vector2f position;
    public:
        MyText(std::string_view, sf::Font&, 
                unsigned int , sf::Color, sf::Vector2f);
        ~MyText();
        void update(float&);
        void render(sf::RenderTarget&);
};

#endif  