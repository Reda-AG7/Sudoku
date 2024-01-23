#include "Game.hpp"


Game::Game(){
    window = new sf::RenderWindow(sf::VideoMode(800,1000), "Sudoku", sf::Style::Close);
    window->setFramerateLimit(60u);
    window->setVerticalSyncEnabled(false);
    
    states.push(new MainState(*window,states));
}

Game::~Game(){
    delete window;
}
void Game::updateEvents(){
    sf::Event e;
    while(window->pollEvent(e)){
        if(e.type == sf::Event::Closed)
            window->close();
    }
}

void Game::update(){
    updateEvents();
    if(!states.empty())
        states.top()->update(dt);
}

void Game::render(){
    window->clear();
    if(!states.empty())
        states.top()->render(*window);
    else exit(EXIT_SUCCESS);
    window->display();
}

void Game::run(){
    while(window->isOpen()){
        update();
        render();
    }
}







    