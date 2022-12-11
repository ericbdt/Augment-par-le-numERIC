#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Enemy.hpp"
#include "Projectile.hpp"

class Enemy; // Prevents circle dependency
class Player
{

private:
    sf::RectangleShape shape;

    float movement_speed;

    void init_var();
    void init_shape();

public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    sf::Vector2f getPosition() const;
    sf::Vector2f getCenter() const;
    sf::Vector2f getDirectionToNearestEnemy(std::vector<Enemy> &enemies) const;

    void update(const sf::RenderTarget *target);
    void updateInput();

    // void updateCollision(const sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
};

#endif