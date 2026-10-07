#pragma once
#include "SFML/Graphics.hpp"

class Screen{
private:

protected:
    const float& dt;
public:
    Screen(const float& dt);

    virtual void update() = 0;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void handleInput() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};