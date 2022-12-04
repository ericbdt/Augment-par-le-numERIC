#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

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

    void update(const sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
};

#endif