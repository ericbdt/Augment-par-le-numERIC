#include "Projectile.hpp"
#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include <vector>

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
void Projectile::update(std::vector<Enemy> enemies)
{
    // Update Movement
    shape.move(speed * direction.x, speed * direction.y);

    // Check Collision
    this->checkAllAttacks(enemies);
}

void Projectile::checkAllAttacks(std::vector<Enemy> &enemies)
{
    // Iterate through the vector of enemies
    std::cout<<enemies.size()<<std::endl;

    for (unsigned int j = 0; j < enemies.size(); j++)
    {
        // Check for collision between the projectile and the enemie
        this->attack(enemies[j]);
    }
    std::cout << enemies.size() << std::endl;


}


void Projectile::attack(Enemy &enemy)
{

    sf::Vector2f thisPos = this->shape.getPosition();
    sf::Vector2f otherPos = enemy.getPosition();
    sf::Vector2f thisSize = this->shape.getSize();
    sf::Vector2f otherSize = enemy.getSize();

    float thisLeft = position.x;
    float thisRight = position.x + thisSize.x;
    float thisTop = thisPos.y;
    float thisBottom = thisPos.y + thisSize.y;
    float otherLeft = otherPos.x;
    float otherRight = otherPos.x + otherSize.x;
    float otherTop = otherPos.y;
    float otherBottom = otherPos.y + otherSize.y;

    // check if the projectile and the enemy are colliding
    if ((thisLeft < otherRight) && (thisRight > otherLeft) && (thisTop < otherBottom) && (thisBottom > otherTop)) 
    {
        updateAttack(&enemy);
    };



}

void Projectile::updateAttack(Enemy *target)
{
    ~target;
    std::cout << "enemi tué" << std::endl;
}




void Projectile::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}