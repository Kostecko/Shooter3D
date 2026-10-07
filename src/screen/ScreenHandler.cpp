#include "ScreenHandler.hpp"

ScreenHandler::ScreenHandler(const float& dt, sf::RenderWindow& win)
 : window(win), 
 gameScr(dt),
 menuScr(dt), 
 screen(&gameScr){

}

void ScreenHandler::update(){
    screen->update();
}

void ScreenHandler::handleEvent(const sf::Event &event)
{
    screen->handleEvent(event);
}

void ScreenHandler::handleInput(){
    screen->handleInput();
}

void ScreenHandler::draw(){
    screen->draw(window);
}