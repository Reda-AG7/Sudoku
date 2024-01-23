#ifndef __MAIN_STATE__H
#define __MAIN_STATE__H

#include "GameState.hpp"
#include "../Components/Button.hpp"
#include <vector>
#include <unordered_map>

class MainState : public State{
    private:
        MyText* title;
        std::vector<Button*> buttons;

        unsigned choice;
        std::unordered_map<int,int> choiceToRange;
    public:

        MainState(sf::RenderWindow&, std::stack<State*>&);
        ~MainState();
        void update(float&);
        void render(sf::RenderTarget&);
        void initButtons();
        void deleteButtons();
        void updateButtons(float& dp);
        void renderButtons(sf::RenderTarget&);
};

#endif
