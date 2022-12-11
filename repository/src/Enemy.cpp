#include "Enemy.hpp"
#include <cmath>
#include <iostream>

void Enemy::init_var()
{
    this->movement_speed = 3.f;
}

void Enemy::init_shape(const sf::RenderWindow &window)
{
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    // fait apparaître les ennemis dans la fenêtre
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
}

Enemy::Enemy(const sf::RenderWindow &window)
{
    this->init_var();
    this->init_shape(window);
}

Enemy::~Enemy()
{
}

sf::Vector2f Enemy::getPosition() const
{
    return (this->shape.getPosition());
}

void Enemy::updateMovement(Player *player)
{
    sf::Vector2f coord_p = player->getPosition();       // coordonnées joueur
    sf::Vector2f coord_npc = this->shape.getPosition(); // coordonnées ennemi

    sf::Vector2f direction = coord_p - coord_npc;                                               // direction vers le joueur
    direction = direction / (std::sqrt(direction.x * direction.x + direction.y * direction.y)); // normalisation
    direction = direction * this->movement_speed;
    // printf("%f,%f \n", direction.x, direction.y);

    this->shape.move(direction.x, direction.y); // puis on bouge
}

float pushback_factor = 0.05;

void Enemy::updateCollision(sf::Vector2f thisPos, sf::Vector2f thisSize, sf::Vector2f otherPos, sf::Vector2f otherSize, Enemy &other)
{
    // Calculate the overlap between the two Enemy objects
    float xOverlap = (thisSize.x + otherSize.x) - std::abs(thisPos.x - otherPos.x);
    float yOverlap = (thisSize.y + otherSize.y) - std::abs(thisPos.y - otherPos.y);

    // Push the two Enemy objects back along the axis with the smallest overlap
    if (xOverlap < yOverlap)
    {
        if (thisPos.x < otherPos.x)
        {
            this->shape.move(-xOverlap * pushback_factor, 0);
            other.shape.move(xOverlap * pushback_factor, 0);
        }
        else
        {
            this->shape.move(xOverlap * pushback_factor, 0);
            other.shape.move(-xOverlap * pushback_factor, 0);
        }
    }
    else
    {
        if (thisPos.y < otherPos.y)
        {
            this->shape.move(0, -yOverlap * pushback_factor);
            other.shape.move(0, yOverlap * pushback_factor);
        }
        else
        {
            this->shape.move(0, yOverlap * pushback_factor);
            other.shape.move(0, -yOverlap * pushback_factor);
        }
    }
}

void Enemy::checkCollision(Enemy &other)
{
    // Get the position and size of the two Enemy objects
    sf::Vector2f thisPos = this->shape.getPosition();
    sf::Vector2f otherPos = other.shape.getPosition();
    sf::Vector2f thisSize = this->shape.getSize();
    sf::Vector2f otherSize = other.shape.getSize();

    // Calculate the bounds of the two Enemy objects
    // (accounting for the origin being in the top left corner)
    float thisLeft = thisPos.x;
    float thisRight = thisPos.x + thisSize.x;
    float thisTop = thisPos.y;
    float thisBottom = thisPos.y + thisSize.y;
    float otherLeft = otherPos.x;
    float otherRight = otherPos.x + otherSize.x;
    float otherTop = otherPos.y;
    float otherBottom = otherPos.y + otherSize.y;

    // Check if the two Enemy objects are colliding
    bool colliding = (thisLeft < otherRight) && (thisRight > otherLeft) && (thisTop < otherBottom) && (thisBottom > otherTop);

    // Handle the collision if necessary
    if (colliding)
    {
        // Push the two Enemy objects back using the updateCollision function
        this->updateCollision(thisPos, thisSize, otherPos, otherSize, other);
    }
}

void Enemy::checkAllCollision(std::vector<Enemy> &enemies)
{
    // Iterate through the vector of enemies
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        // Compare the current enemy with all the other enemies in the vector
        for (unsigned int j = i + 1; j < enemies.size(); j++)
        {
            // Check for collision between the two enemies
            enemies[i].checkCollision(enemies[j]);
        }
    }
}

void Enemy::update(Player *player, std::vector<Enemy> &enemies, const sf::RenderTarget *target)
{
    // Déplacement automatique
    this->updateMovement(player);

    // Détéction et correction Collision
    this->checkAllCollision(enemies);
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
