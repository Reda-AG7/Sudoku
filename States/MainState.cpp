#include "MainState.hpp"
/*
Choice :
    0 --> no button is clicked on
    1 --> new Game is clicked on
    2 --> play with friend
    3 --> quit 
*/
MainState::MainState(sf::RenderWindow& window, std::stack<State*>& states) : 
        State(window, states){

        choice = 0; 
        title = new MyText("Sudoku",*titleFont, 
                130u,sf::Color::White,
                sf::Vector2f(250.0f,200.0f));
        initButtons();
        //mapping Choice to range
        choiceToRange[0] = 3;
        choiceToRange[1] = 7;
        choiceToRange[4] = 3;

}
MainState::~MainState(){
    delete title;
    deleteButtons();
}

void MainState::update(float& dt){
    
    title->update(dt);
    updateButtons(dt);
}

void MainState::render(sf::RenderTarget& target){
    target.draw(*background);
    title->render(target);
    renderButtons(target);
    
    
}
void MainState::updateButtons(float& dt){
    sf::Vector2f mousePosition = sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x),
                                static_cast<float>(sf::Mouse::getPosition(*window).y));
    for(int i = 0;i<choiceToRange[choice];++i)
        buttons[i]->update(dt, mousePosition);
        //Quit
    if(buttons[0]->isPressed()) {
        choice = 1;
        buttons[0]->setPressed(false);
    }
    else if(buttons[1]->isPressed()){
        //play against friend
    }
    else if(buttons[2]->isPressed()) states->pop();
    else if(buttons[3]->isPressed()) choice = 4;
    else if(buttons[4]->isPressed()) choice = 5;
    else if(buttons[5]->isPressed()) choice = 6;
    else if(buttons[6]->isPressed()) choice = 0;
    if(choice>=3 && choice <=6){
        unsigned difficulty = choice%3;
        choice = 0;
        states->push(new GameState(*window,*states,difficulty));
    }
}
void MainState::deleteButtons(){
    for(auto& btn: buttons)
        delete btn;
}

void MainState::initButtons(){
    buttons.resize(7);
    float xOffset = 150.f;
    float yOffset = 400.f;
    //Choice 0
    buttons[0] = new Button(200.0f, 50.0f,"New Game",*titleFont, 
                20u,sf::Color::White,
                sf::Vector2f(xOffset,yOffset));
    buttons[1] = new Button(200.0f, 50.0f,"Invite Friend",*titleFont, 
                20u,sf::Color::White,
                sf::Vector2f(xOffset,yOffset + 60.0f));
    buttons[2] = new Button(200.0f, 50.0f,"Quit",*titleFont, 
            20u,sf::Color::White,
            sf::Vector2f(xOffset,yOffset + 120.0f));
    //Choice 1
    float xOffset2 = 370.f;
    float yOffset2 = 410.f;
    buttons[3] = new Button(200.0f, 50.0f,"Easy",*titleFont, 
            20u,sf::Color::White,
            sf::Vector2f(xOffset2,yOffset2));
    buttons[4] = new Button(200.0f, 50.0f,"Medium",*titleFont, 
            20u,sf::Color::White,
            sf::Vector2f(xOffset2,yOffset2 + 60.0f));
    buttons[5] = new Button(200.0f, 50.0f,"Hard",*titleFont, 
            20u,sf::Color::White,
            sf::Vector2f(xOffset2,yOffset2 + 120.0f));
    buttons[6] = new Button(200.0f, 50.0f,"Back",*titleFont, 
            20u,sf::Color::White,
            sf::Vector2f(xOffset2,yOffset2 + 180.0f));
    
}

void MainState::renderButtons(sf::RenderTarget& target){
    for(int i=0;i<choiceToRange[choice];++i)
        buttons[i]->render(target);
}