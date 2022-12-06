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

void Enemy::updateMovement(Player *player)
{
    sf::Vector2f coord_p = player->get_Position();      // coordonnées joueur
    sf::Vector2f coord_npc = this->shape.getPosition(); // coordonnées ennemi

    sf::Vector2f direction = coord_p - coord_npc;                                               // direction vers le joueur
    direction = direction / (std::sqrt(direction.x * direction.x + direction.y * direction.y)); // normalisation
    direction = direction * this->movement_speed;
    // printf("%f,%f \n", direction.x, direction.y);

    this->shape.move(direction.x, direction.y); // puis on bouge
}

void Enemy::update(Player *player, const sf::RenderTarget *target)
{

    // Collison
    // this->updateCollision(target)

    // Déplacement automatique
    this->updateMovement(player);
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
