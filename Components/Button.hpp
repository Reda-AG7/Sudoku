#ifndef __BUTTON__H
#define __BUTTON__H

#include "MyText.hpp"


class Button{
    private:
        sf::RectangleShape rec;
        MyText* text;
        float width, height;
        sf::Vector2f position;

        bool pressed;

        sf::Color idle,hover, active;

    public:
        Button(float width, float height, 
                std::string_view, sf::Font&, 
                unsigned int , sf::Color, sf::Vector2f);
        ~Button();
        void update(float&, sf::Vector2f);
        void render(sf::RenderTarget&);
        bool isPressed() const;
        void setPressed(bool);

};

#endif