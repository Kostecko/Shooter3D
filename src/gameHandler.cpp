#include "gameHandler.hpp"
#include <string.h>

//---------------INTERNAL FUNCTIONS--------------------

void gameHandler::update(){
    deltaTime = clock.restart().asSeconds();
    scrHandler.update();
    scrHandler.handleInput();
}

void gameHandler::handleEvent(sf::Event event){
    if(event.is<sf::Event::Closed>()) window.close();
}

void gameHandler::draw(){
    window.clear();
    scrHandler.draw();
    window.display();
}

//------------------KONSTRUKTOR------------------------

gameHandler::gameHandler() : scrHandler(deltaTime, window, win_width, win_height){
    window.create(
        sf::VideoMode({win_width, win_height}), 
        "Shooter 3D",
        sf::State::Windowed);
}

//---------------EXTERNAL FUNCTIONS--------------------

void gameHandler::gameLoop(){
    while(window.isOpen()){
        while(const std::optional event = window.pollEvent())
            handleEvent(*event);
        




        update();
        draw();
    }
}