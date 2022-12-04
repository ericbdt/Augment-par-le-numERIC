#include "Enemy.hpp"

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
            static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().height)));
}

Enemy::Enemy(const sf::RenderWindow &window)
{
    this->init_var();
    this->init_shape(window);
}

Enemy::~Enemy()
{
}

void Enemy::update(const sf::RenderTarget *target)
{
    // Collison
    // this->updateCollision(target)

    // Entrées clavier
    // this->updateInput();
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
