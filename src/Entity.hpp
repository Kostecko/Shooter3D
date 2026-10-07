#pragma once
#include <SFML/Graphics.hpp>
#include "MapHandler.hpp"

class Entity : public sf::CircleShape{
private:
    sf::Vector2u toMapPos(sf::Vector2f pos);
    const MapHandler& map;

protected:
    const float movespeed = 200;
    const float rotspeed = 200;
    const float& dt;
    const float radius = 20.f;
    sf::Vector2f pos = {0,0};
    float rotrad = 0;

    sf::Vector2i collision(sf::Vector2f dir);
public:
    Entity(const float& dt, const MapHandler& map);
    
    
};