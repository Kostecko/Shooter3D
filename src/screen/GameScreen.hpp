#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "../Player.hpp"
#include "../MapHandler.hpp"

class GameScreen : public Screen{
private:
    Player player;
    const MapHandler map;
public:
    GameScreen(const float& dt);

    void update();
    void handleEvent(const sf::Event& event);
    void handleInput();
    void draw(sf::RenderWindow& window) override;
};