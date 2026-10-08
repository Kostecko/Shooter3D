#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "MenuScreen.hpp"
#include "GameScreen.hpp"

using ucint = unsigned const int;

class ScreenHandler{
private:
    // MENUSCREEN I GAMESCREEN MUSZA BYC TWORZONE DOPIERO GDY GRACZ WCHODZI DO DANEGO SCREENA, A POZOSTALE NISZCZONE
    // TERAZ WSZYSTKIE OBIEKTY JEDNOCZESNIE ISTNIEJA
    sf::RenderWindow& window;
    MenuScreen menuScr;
    GameScreen gameScr;
    const float& dt;

    Screen* screen = nullptr;
public:
    ScreenHandler(const float& dt, sf::RenderWindow &win, ucint w, ucint h);

    void update();
    void handleEvent(const sf::Event& event);
    void handleInput();

    void draw();
};