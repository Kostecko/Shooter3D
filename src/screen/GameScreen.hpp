#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Screen.hpp"
#include "../Player.hpp"
#include "../MapHandler.hpp"

using ucint = unsigned const int;

struct ray{
    sf::Vector2f position = {0.f,0.f};
    float length = 0.f;
    sf::Angle angle = sf::degrees(0);
    bool isVertical = 0;
    sf::Color color = {0,0,0};
    //sf::Vector2i block ={0,0};
};

class GameScreen : public Screen{
private:
    Player player;
    const sf::Vector2f& ppos;
    const float& protrad;


    const float fov = 60.f;
    const float fovaccuracy = 200.f;
    const float cell_size = 90.f;
    
    const MapHandler map;
    const std::vector<ray> raycast(const sf::Vector2u map_pos) const;
    std::vector<sf::RectangleShape> render3D() const;

public:
    GameScreen(const float& dt, ucint w,  ucint h);

    void update() override;
    void handleEvent(const sf::Event& event) override;
    void handleInput() override;
    void draw(sf::RenderWindow& window) const override;
};