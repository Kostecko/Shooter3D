#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>

using ucint = unsigned const int;

class MapHandler{
private:
    std::vector<std::string> mapstring;
    const sf::Vector2u size;
    const std::unordered_map<char, sf::Color> cellColorMap;
public:
    MapHandler(ucint width, ucint height);
    
    sf::Vector2u toMapPos(sf::Vector2f pos) const;
    char getMapChar(ucint x, ucint y) const;
    const sf::Color getCellColor(const char c) const;
};