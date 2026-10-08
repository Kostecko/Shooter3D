#include "ScreenHandler.hpp"
#include <iostream>
ScreenHandler::ScreenHandler(const float& dt, sf::RenderWindow& win, ucint w, ucint h)
 : window(win), 
 gameScr(dt, w, h),
 menuScr(dt, w, h), 
 screen(&gameScr),
 dt(dt){

}

void ScreenHandler::update(){
    static float counter =0.f; 
    static float sec=0.f;
    static int fps=0;
    static int tick =0;
    counter += 1.f/dt;
    sec += dt;
    tick+=1;
    
    if(sec > 0.5){
        fps = static_cast<int>(counter/tick);
        sec = 0.f;
        counter = 0.f;
        tick = 0;
    }

    window.setTitle("FPS: " + std::to_string(fps));
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