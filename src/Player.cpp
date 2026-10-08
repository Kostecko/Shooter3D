#include "Player.hpp"
#include <cmath>
#define here printf("here");

//-----------------INTERNAL--------------------------



//--------------------KONSTRUKTOR--------------------

Player::Player(const float& delta, const MapHandler& map) : Entity(delta, map){
    if(txt.loadFromFile(ASSETS_DIR "2DPlayerTexture.png"))
        setTexture(&txt);
        
    setPosition({700,400});
    setRadius(radius);
    setOrigin({radius, radius});
}



//----------------------EXTERNAL------------------

void Player::update(){
    pos = getPosition();
    rotrad = getRotation().asRadians();   
}

void Player::handleInput(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) rotate(sf::degrees(rotspeed * dt));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) rotate(sf::degrees(-rotspeed * dt));

    float _sin = sin(rotrad);
    float _cos = cos(rotrad);

    sf::Vector2f dir{0.f,0.f}; 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) dir += {_sin, -_cos};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) dir += {-_sin, _cos};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dir += {-_cos, -_sin};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dir += {_cos, _sin};

    float len = hypot(dir.x, dir.y);

    if(len > 1e-6f){
        dir /= len;
        sf::Vector2i col = collision(dir);
        //printf("%i\t%i\n", col.x, col.y);
        move({!col.x * dir.x * movespeed * dt, !col.y * dir.y * movespeed * dt});
    }
}

void Player::handleEvent(){

}

void Player::draw(sf::RenderWindow &window) const{
    window.draw(*this);
}
