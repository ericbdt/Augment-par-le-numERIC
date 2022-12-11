#include "Projectile.hpp"
#include <cmath>
#include <iostream>

void Projectile::init_var()
{
    // Normalize the direction vector
    this->direction = this->direction / std::sqrt(this->direction.x * this->direction.x + this->direction.y * this->direction.y);
}

void Projectile::init_shape()
{
    // Create the shape for the projectile
    shape.setPosition(position);
    shape.setSize({10.f, 10.f});
    shape.setFillColor(sf::Color::White);
}

Projectile::Projectile(sf::Vector2f position, sf::Vector2f direction, float speed, float damage, bool friendly)
    : position(position), direction(direction), speed(speed), damage(damage), friendly(friendly)
{
    this->init_var();
    this->init_shape();
}

Projectile::~Projectile()
{
}

// Get the damage dealt by the projectile
float Projectile::getDamage() const
{
    return damage;
}

// Check if the projectile is friendly (i.e. fired by the player)
bool Projectile::isFriendly() const
{
    return friendly;
}

sf::RectangleShape Projectile::getShape() const
{
    return shape;
}

// Update the position of the projectile
void Projectile::update()
{
    // Update Movement
    shape.move(speed * direction.x, speed * direction.y);

    // Check Collision
}

void Projectile::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}