#include "GameScreen.hpp"


//----------------------------KONSTRUKTOR--------------------------------
GameScreen::GameScreen(const float& dt) : Screen(dt), map(16, 9), player(dt, map){

}

//---------------------------EXTERNAL----------------------------------

void GameScreen::update(){
    player.update();
}


void GameScreen::handleEvent(const sf::Event &event){
    player.handleEvent();
}

void GameScreen::handleInput(){
    player.handleInput();
}

void GameScreen::draw(sf::RenderWindow &window){
    player.draw(window);
}