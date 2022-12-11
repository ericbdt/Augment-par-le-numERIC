#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>

class Projectile
{
private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f direction;
    float speed;
    float damage;
    bool friendly; // Whether the projectile is friendly or not (no friendly fire)

    void init_var();
    void init_shape();

public:
    Projectile(sf::Vector2f position, sf::Vector2f direction, float speed, float damage, bool friendly);
    virtual ~Projectile();

    // Update the position of the projectile
    void update();
    // Render the projectile
    void render(sf::RenderTarget *target);

    float getDamage() const;
    bool isFriendly() const; // Check if the projectile is friendly (i.e. fired by the player)

    // Get the shape of the projectile
    sf::RectangleShape getShape() const;
};

#endif