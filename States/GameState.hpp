#ifndef __GAME_STATE__H
#define __GAME_STATE__H

#include "State.hpp"
#include "../Components/Button.hpp"
#include "../Components/Cell.hpp"
#include <chrono>
#include <vector>

using timePoint = std::chrono::steady_clock::time_point;

class GameState : public State{
    private:
        timePoint t_start, t_end;
        unsigned difficulty;
        std::vector<std::vector<Cell*>> board;
        MyText* time;
    public:
        GameState(sf::RenderWindow&, std::stack<State*>&, unsigned&);
        ~GameState();
        void update(float&);
        void render(sf::RenderTarget&);
        void initBoard();
        void renderBoard(sf::RenderTarget&) const;
        void updateBoard(float&);
};

#endif