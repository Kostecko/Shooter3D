#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.hpp"

using ucint = unsigned const int;

class MenuScreen : public Screen{
private:

public:
    MenuScreen(const float& dt, ucint w, ucint h);

    void update();
    void handleEvent(const sf::Event& event);
    void handleInput();
    void draw(sf::RenderWindow& window) const override;
};