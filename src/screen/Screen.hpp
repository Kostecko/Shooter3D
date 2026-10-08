#pragma once
#include "SFML/Graphics.hpp"

using ucint = unsigned const int;

class Screen{
private:

protected:
    const float& dt;
    ucint win_width = 0, win_height = 0;
public:
    Screen(const float& dt, ucint w, ucint h);

    virtual void update() = 0;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void handleInput() = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
};