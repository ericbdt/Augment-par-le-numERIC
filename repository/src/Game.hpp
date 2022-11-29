#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
/*
Classe qui agit comme moteur de jeu
en gros un Wrapper
*/

class Game
{
private:
    // Variables

    // Window
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event ev;

    // Private functions
    void init_var(); // initialise variables
    void init_win(); // initailise la fenêtre

public:
    // Ctors & Dtors
    Game();
    virtual ~Game();

    // Getters
    const bool isRunning() const;

    // Functions
    void update();
    void updateEvents();
    void render();
};

#endif