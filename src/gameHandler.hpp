#pragma once
#include "SFML/Graphics.hpp"
#include "screen/ScreenHandler.hpp"
#include "MapHandler.hpp"

class gameHandler{
private:
    const unsigned int win_width = 1440, win_height = 810;

    sf::RenderWindow window;
    sf::Clock clock;
    float deltaTime = 0;

    ScreenHandler scrHandler;

    void update();
    void handleEvent(sf::Event event);
    void draw();
public:
    gameHandler();

    void gameLoop();
};