#include "Entity.hpp"
#include <cmath>
#include <climits>
//------------------------INTERNAL---------------------------

sf::Vector2u Entity::toMapPos(sf::Vector2f pos){
    //NA RAZIE NA SZTYWNO USTAWIAM WINWIDTH I WINHEIGHT, W PRZYSZLOSCI STWORZE KLASE MAP I TAM BEDZIE FUNKCJA TOMAPPOS I ONA BEDZIE MIALA INFO O 
    //WINDOW
    //CELLSIZE USTAWIAM NWD(1440, 810) = 90 

    const float win_width = 1440.f;
    const float win_height = 810.f;
    const float cell_size = 90.f;

    if (pos.x < 0 || 
        pos.x >= win_width || 
        pos.y < 0 || 
        pos.y >= win_height || 
        !std::isfinite(pos.x) || 
        !std::isfinite(pos.y)) return { UINT_MAX, UINT_MAX };

    return {
         static_cast<unsigned>(pos.x / cell_size), 
         static_cast<unsigned>(pos.y / cell_size) };
}

//------------------------PROTECTED---------------------------

sf::Vector2i Entity::collision(sf::Vector2f dir){
    sf::Vector2u oldmpos = toMapPos(pos);
    sf::Vector2f newpos = {pos.x + dir.x * movespeed * dt + dir.x * radius, 
                            pos.y + dir.y * movespeed * dt + dir.y * radius};
    sf::Vector2u newmpos = toMapPos(newpos);

    bool hitX = map.getMapChar({oldmpos.x, newmpos.y}) == '#';
    bool hitY = map.getMapChar({newmpos.x, newmpos.y}) == '#';
    bool hitDiag = map.getMapChar(newmpos) == '#';

    return {hitX || hitDiag, hitY || hitDiag};
}


//------------------------KONSTRUKTOR---------------------------

Entity::Entity(const float& dt, const MapHandler& map) : dt(dt), map(map){
    
}

//------------------------EXTERNAL---------------------------
