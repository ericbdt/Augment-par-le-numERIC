#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// TO COMPILE LE GAME
// g++ -c main.cpp
// g++ main.o -o le_game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

// using namespace sf;

int main()
{
    // Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Le Game", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    // Game loop
    while (window.isOpen())
    {
        // Event polling
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                break;
            }
        }

        // Update

        // Render
        window.clear(sf::Color::Blue); // Clear old frame

        // DRAW HERE

        window.display(); // Tell app the window is done drawing
    }

    // End
    printf("sheesh\n");
    return (0);
}