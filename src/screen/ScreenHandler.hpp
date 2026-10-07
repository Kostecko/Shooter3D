#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "MenuScreen.hpp"
#include "GameScreen.hpp"

class ScreenHandler{
private:
    // MENUSCREEN I GAMESCREEN MUSZA BYC TWORZONE DOPIERO GDY GRACZ WCHODZI DO DANEGO SCREENA, A POZOSTALE NISZCZONE
    // TERAZ WSZYSTKIE OBIEKTY JEDNOCZESNIE ISTNIEJA
    sf::RenderWindow& window;
    MenuScreen menuScr;
    GameScreen gameScr;

    Screen* screen = nullptr;
public:
    ScreenHandler(const float& dt, sf::RenderWindow &win);

    void update();
    void handleEvent(const sf::Event& event);
    void handleInput();

    void draw();
};