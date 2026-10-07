#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MapHandler{
private:
    std::vector<std::string> mapstring;
    const sf::Vector2u size;

public:
    MapHandler(const unsigned int width, const unsigned int height);
    
    char getMapChar(sf::Vector2u index) const;
};