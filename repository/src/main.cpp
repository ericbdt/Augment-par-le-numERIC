#include <cstdio>
#include <iostream>
#include "Game.hpp"

// TO COMPILE LE GAME
// g++ -c main.cpp
// g++ main.o -o le_game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

// using namespace sf;

int main()
{

    // Init game engine
    Game game;

    // Game loop : boucle principale
    while (game.isRunning())
    {
        game.update();

        game.render();
    }

    // End
    printf("sheesh\n");
    return (0);
}