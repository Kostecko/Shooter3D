#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class MenuScreen : public Screen{
private:

public:
    MenuScreen(const float& dt);

    void update();
    void handleEvent(const sf::Event& event);
    void handleInput();
    void draw(sf::RenderWindow& window) override;
};