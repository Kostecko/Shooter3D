#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "MapHandler.hpp"

class Player : public Entity{
private:
    sf::Texture txt;
    
public:
    Player(const float& delta, const MapHandler& map);
    
    void update();
    void handleInput();
    void handleEvent();
    void draw(sf::RenderWindow& window) const;
};