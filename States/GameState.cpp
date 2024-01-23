#include "GameState.hpp"


GameState::GameState(sf::RenderWindow& window, 
                    std::stack<State*>& states, unsigned&  difficulty) : 
                    State(window, states){
    this->difficulty = difficulty;

    initBoard();
    // time = new MyText("00:00",*regularFont,20u,
    //                 sf::Color::Yellow,
    //                 sf::Vector2f(500.0f,50.0f));

}
GameState::~GameState(){
    //delete time;
}

void GameState::update(float& dt){
    updateBoard(dt);
}
void GameState::render(sf::RenderTarget& target){
    target.draw(*background);
    renderBoard(target);
    //time->render(target);
}

void GameState::initBoard(){
    board = std::vector(9,std::vector<Cell*>(9));
    float xOffset = 170.0f;
    float yOffset = 150.0f;
    unsigned sideLength = 50u;
    float space = 2.0f;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            board[i][j] = new Cell(sideLength,
                                    sf::Vector2f(i*(sideLength+space) + yOffset, 
                                                j*(sideLength+space) + xOffset));
        }
    }
}

void GameState::renderBoard(sf::RenderTarget& target) const{
    for(auto& v : board){
        for(auto& cell : v){
            cell->render(target);
        }
    }
}

void GameState::updateBoard(float& dt){
    sf::Vector2f mousePosition = sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x),
                                static_cast<float>(sf::Mouse::getPosition(*window).y));
    for(auto& v : board){
        for(auto& cell : v){
            cell->update(dt, mousePosition);
        }
    }
}
