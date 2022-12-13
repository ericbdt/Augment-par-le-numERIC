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

// Created libraries
#include "Player.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

/*
Class that acts as the game engine : wrapper
*/

class Game
{
private:
    // Variables

    // Window
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event ev;

    // World
    sf::Texture world_background_texture;
    sf::Sprite world_background_sprite;

    // Player
    Player player;
    std::vector<Projectile> friendly_projectiles;
    float fire_timer;
    float fire_timer_max;

    // Enemies
    std::vector<Enemy> enemies;
    float spawn_timer_max;
    float spawn_timer;
    long unsigned max_enemies;

    // Private functions
    void init_var(); // initializes variables
    void init_win(); // initailizes the window
    void init_world();

public:
    // Ctors & Dtors
    Game();
    virtual ~Game();

    // Getters
    bool isRunning() const;

    // Event Functions
    void spawnEnemies();
    void playerFire();

    // Game Functions
    void update();
    void updateEvents();
    void render();
    void renderWorld();
};

#endif