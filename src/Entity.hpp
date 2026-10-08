#pragma once
#include <SFML/Graphics.hpp>
#include "MapHandler.hpp"

class Entity : public sf::CircleShape{
private:
    const MapHandler& map;

protected:
    const float& dt;

    const float movespeed = 200;
    const float rotspeed = 90;
    const float radius = 20.f;

    sf::Vector2f pos = {0,0};
    float rotrad = 0;


    sf::Vector2i collision(sf::Vector2f dir);
public:
    Entity(const float& dt, const MapHandler& map);
    
    virtual void draw(sf::RenderWindow& window) const = 0;
    const sf::Vector2f& getPosRef() const;
    const float& getRotradRef() const;
};