#ifndef GAME_H
#define GAME_H

// Librairies générales
#include <iostream>
#include <ctime>
#include <vector>

// Librairies SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// Librairies crées
#include "Player.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

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

    // Player
    Player player;
    std::vector<Projectile> friendly_projectiles;
    float fire_timer;
    float fire_timer_max;

    std::vector<Enemy> enemies;
    float spawn_timer_max;
    float spawn_timer;
    long unsigned max_enemies;

    // Private functions
    void init_var(); // initialise variables
    void init_win(); // initailise la fenêtre

public:
    // Ctors & Dtors
    Game();
    virtual ~Game();

    // Getters
    bool isRunning() const;

    // Event Functions
    void spawnEnemies();
    void playerFire();
    void popEnemy(int e);

    // Game Functions
    void update();
    void updateEvents();
    void render();
};

#endif