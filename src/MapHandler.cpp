#include "MapHandler.hpp"
#include <iostream>

MapHandler::MapHandler(const unsigned int width, const unsigned int height) : size({width, height}){
    mapstring = {
        "################",
        "#              #",
        "#              #",
        "#              #",
        "#              #",
        "#              #",
        "#              #",
        "#              #",
        "################"
    };
}

char MapHandler::getMapChar(sf::Vector2u index) const{
    if(index.x >= size.x|| index.y >= size.y) return 0;
    
    return mapstring[index.y][index.x];
}