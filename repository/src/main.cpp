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
    // Window : création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Le Game", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    sf::Event ev;

    // Game loop : boucle principale
    while (window.isOpen())
    {
        // Event polling : on scan pour les évènements et on stocke dans ev
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

        // Update : Mise à jour de l'état du jeu

        // Render : Dessiner le nouvel état
        window.clear(sf::Color::Blue); // Clear la dernière image

        // DRAW HERE

        // Display : Afficher la nouvelle frame
        window.display(); // Dit à la fenêtre qu'on a finit de dessiner
    }

    // End
    printf("sheesh\n");
    return (0);
}