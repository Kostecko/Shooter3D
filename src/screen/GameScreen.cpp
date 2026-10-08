#include "GameScreen.hpp"
#include <cmath>
#include <iostream>
#include <chrono>

//-----------------------INTERNAL----------------------------------------

const std::vector<ray> GameScreen::raycast(const sf::Vector2u map_pos) const{
    std::vector<ray> output;
    output.reserve(fovaccuracy);

    static float half_fov = fov/2.f;
    static float fov_step = fov/fovaccuracy;
    
    for(float f = -half_fov; f<half_fov; f+=fov_step){
        float angrad = protrad + f * M_PI / 180.f;
        int mapX = map_pos.x, mapY = map_pos.y;

        sf::Vector2f rayDir = {
            std::sin(angrad),
            -std::cos(angrad)
        };
        sf::Vector2i step = {
            rayDir.x < 0 ? -1 : 1,
            rayDir.y < 0 ? -1 : 1,
        };
        sf::Vector2f delta = {
            std::abs(rayDir.x) < 1e-6f ? INFINITY : cell_size / std::abs(rayDir.x),
            std::abs(rayDir.y) < 1e-6f ? INFINITY : cell_size / std::abs(rayDir.y),
        };
        sf::Vector2f side = {
            rayDir.x < 0 ?
            delta.x == INFINITY ? delta.x : (ppos.x - mapX * cell_size) / std::abs(rayDir.x) :
            delta.x == INFINITY ? delta.x : ((mapX + 1) * cell_size - ppos.x) / std::abs(rayDir.x),

            rayDir.y < 0 ?
            delta.y == INFINITY ? delta.y : (ppos.y - mapY * cell_size) / std::abs(rayDir.y) :
            delta.y == INFINITY ? delta.y : ((mapY + 1) * cell_size - ppos.y) / std::abs(rayDir.y)
        };

        while(1){
            char c;
            if(side.x < side.y){
                mapX += step.x;
                c = map.getMapChar(mapX, mapY);
                if(c=='\0') break;
                if(c != ' '){
                    sf::Vector2f position = {ppos.x + rayDir.x * side.x, ppos.y + rayDir.y * side.x};
                    output.push_back({position, side.x, sf::degrees(f), true, map.getCellColor(c)});
                    break;
                }

                side.x += delta.x;
            }
            else if(side.y < side.x){
                mapY += step.y;
                c = map.getMapChar(mapX, mapY);

                if(c=='\0') break;
                if(c != ' '){
                    sf::Vector2f position = {ppos.x + rayDir.x * side.y, ppos.y + rayDir.y * side.y};
                    output.push_back({position, side.y, sf::degrees(f), false, map.getCellColor(c)});
                    break;
                }

                side.y += delta.y;
            }
            else{
                int diagX = mapX + step.x;
                int diagY = mapY + step.y;

                char cx = map.getMapChar(diagX, mapY), 
                cy = map.getMapChar(mapX, diagY), 
                cd = map.getMapChar(diagX, diagY);

                if(cx=='\0' || cy=='\0' || cd=='\0') break;

                bool hitX = cx != ' ';
                bool hitY = cy != ' ';
                bool hitDiag = cd != ' ';
                
                if(hitX || hitY || hitDiag){
                    sf::Vector2i finalmap =
                        hitX ? sf::Vector2i(diagX, mapY) :
                        hitY ? sf::Vector2i(mapX, diagY) :
                            sf::Vector2i(diagX, diagY);

                    sf::Vector2f position = {ppos.x + rayDir.x * side.x, ppos.y + rayDir.y * side.x};
                    output.push_back({position, side.x, sf::degrees(f), true, map.getCellColor(map.getMapChar(finalmap.x, finalmap.y))});
                    break;
                }
                mapX = diagX;
                mapY = diagY;
                
                side.y +=delta.y;
                side.x +=delta.x;
            }
        }

    }
    return output;
}

std::vector<sf::RectangleShape> GameScreen::render3D() const{
    std::vector<sf::RectangleShape> output;
    const std::vector<ray> rays = raycast(map.toMapPos(ppos));
    
    sf::RectangleShape block;
    for (int i = 0; i < rays.size(); i++) {
        float len = rays[i].length * std::cos(rays[i].angle.asRadians());
        float scale = 50.f / len;
        float chunkwidth = float(win_width) / float(rays.size());
        float chunkheight = win_height * scale;

        block.setSize({chunkwidth,chunkheight});
        block.setOrigin({ 0, chunkheight / 2.f });
        block.setPosition({ i * chunkwidth, win_height/2.f});

        if(rays[i].isVertical) block.setFillColor(rays[i].color);
        else block.setFillColor(rays[i].color * sf::Color(150, 150, 150));

        output.push_back(block);
    }
    return output;
}

//----------------------------KONSTRUKTOR--------------------------------

GameScreen::GameScreen(const float &dt, ucint w, ucint h):
Screen(dt, w, h), 
player(dt, map),
ppos(player.getPosRef()),
protrad(player.getRotradRef()),
map(16, 9)
{
   
}

//---------------------------EXTERNAL----------------------------------

void GameScreen::update(){
    player.update();
}

void GameScreen::handleEvent(const sf::Event &event){
    player.handleEvent();
}

void GameScreen::handleInput(){
    player.handleInput();
}

void GameScreen::draw(sf::RenderWindow &window) const{
    //player.draw(window);
    for(auto block : render3D()) window.draw(block);
}