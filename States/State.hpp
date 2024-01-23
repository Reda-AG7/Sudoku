#ifndef __STATE__H
#define __STATE__H
#include "SFML/Graphics.hpp"
#include<stack>

class State{
    protected:
        sf::RectangleShape* background;
        std::stack<State*>* states;
        sf::RenderWindow* window;


        float width, height;

        sf::Font* titleFont, * regularFont;
    public:
        State(sf::RenderWindow&, std::stack<State*>&);
        virtual ~State();
        virtual void update(float&) = 0;
        virtual void render(sf::RenderTarget&) = 0;
        void initFonts();
};

#endif