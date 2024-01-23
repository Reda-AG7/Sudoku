#ifndef __GAME__H
#define __GAME__H

#include "SFML/Graphics.hpp"
#include <stack>
#include "MainState.hpp"
class Game{
    private:
        sf::RenderWindow* window;
        std::stack<State*> states;
        float dt;
        sf::Clock clock;
    public:
        Game();
        ~Game();
        void updateEvents();
        void update();
        void render();
        void run();
};



#endif