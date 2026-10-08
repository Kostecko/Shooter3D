#include "MapHandler.hpp"
#include <iostream>
#include <cmath>
#include <climits>


//-----------------------KONSTRUKTOR------------------------------

MapHandler::MapHandler(ucint width, ucint height) : 
size({width, height}),
cellColorMap({
    {'#', sf::Color::Blue}, 
    {'Y', sf::Color::Yellow}, 
    {'G', sf::Color::Green}, 
    {'M', sf::Color::Magenta}}),
mapstring({
        "################",
        "#              #",
        "## MMMMMMMMMM ##",
        "#              #",
        "#   Y    GG    #",
        "#         G ####",
        "#   MMMMMMM    #",
        "#              #",
        "################"
    }){

}

//-------------------------EXTERNAL----------------------


sf::Vector2u MapHandler::toMapPos(sf::Vector2f pos) const{
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

    unsigned int x = static_cast<unsigned>(pos.x / cell_size);
    unsigned int y = static_cast<unsigned>(pos.y / cell_size);

    return {x, y};
}

char MapHandler::getMapChar(ucint x, ucint y) const
{
    if(x >= size.x|| y >= size.y) return 0;
    
    return mapstring[y][x];
}

const sf::Color MapHandler::getCellColor(const char c) const
{
    return cellColorMap.at(c);
}
