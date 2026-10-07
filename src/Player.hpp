#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "MapHandler.hpp"

class Player : public Entity{
private:
    const float rotspeed = 180.f;
    const float movespeed = 400.f;
    const float radius = 20.f;

    sf::Texture txt;
    public:
    Player(const float& delta, const MapHandler& map);
    
    void update();
    void handleInput();
    void handleEvent();
    void draw(sf::RenderWindow& window);
};