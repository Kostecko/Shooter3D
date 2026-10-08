#include "Entity.hpp"
#include <cmath>
#include <climits>
//------------------------INTERNAL---------------------------

//------------------------PROTECTED---------------------------

sf::Vector2i Entity::collision(sf::Vector2f dir){
    sf::Vector2u oldmpos = map.toMapPos(pos);
    sf::Vector2f newpos = {pos.x + dir.x * movespeed * dt + dir.x * radius, 
                            pos.y + dir.y * movespeed * dt + dir.y * radius};
    sf::Vector2u newmpos = map.toMapPos(newpos);
    
    char c = map.getMapChar(oldmpos.x, newmpos.y);
    bool hitX = c != ' ' && c != '\0';

    c = map.getMapChar(newmpos.x, oldmpos.y);
    bool hitY = c != ' ' && c != '\0';

    c = map.getMapChar(newmpos.x, newmpos.y);
    bool hitDiag = c != ' ' && c != '\0';

    return {hitX || hitDiag, hitY || hitDiag};
}


//------------------------KONSTRUKTOR---------------------------

Entity::Entity(const float& dt, const MapHandler& map) : dt(dt), map(map){
    
}

const sf::Vector2f& Entity::getPosRef() const{
    return pos;
}

const float& Entity::getRotradRef() const{
    return rotrad;
}

//------------------------EXTERNAL---------------------------
