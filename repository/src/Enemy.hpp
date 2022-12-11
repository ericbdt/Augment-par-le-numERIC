#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.hpp"
#include "Projectile.hpp"

class Player; // Prevents circle dependency
class Enemy
{
private:
    sf::RectangleShape shape;

    float movement_speed;

    void init_var();
    void init_shape(const sf::RenderWindow &window);

public:
    Enemy(const sf::RenderWindow &window);
    virtual ~Enemy();

    sf::Vector2f getPosition() const;

    void update(Player *player, std::vector<Enemy> &enemies, const sf::RenderTarget *target);
    void updateMovement(Player *player);

    void updateCollision(sf::Vector2f thisPos, sf::Vector2f thisSize, sf::Vector2f otherPos, sf::Vector2f otherSize, Enemy &other);
    void checkCollision(Enemy &other);
    void checkAllCollision(std::vector<Enemy> &enemies);

    void render(sf::RenderTarget *target);
};

#endif