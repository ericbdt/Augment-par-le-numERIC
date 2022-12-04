#include "Player.hpp"

void Player::init_var()
{
    this->movement_speed = 5.f;
}

void Player::init_shape()
{
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setSize(sf::Vector2f(40.f, 40.f));
}

Player::Player(float x, float y)
{
    this->shape.setPosition(x, y);

    this->init_var();
    this->init_shape();
}

Player::~Player()
{
}

// Entrées clavier
void Player::updateInput()
{
    // Gauche
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->shape.move(-this->movement_speed, 0.f);
    }

    // Droite
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movement_speed, 0.f);
    }

    // Utilisation de else if car on ne va pas utiliser les 2 en même temps

    // Haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->shape.move(0.f, -this->movement_speed);
    }

    // Bas
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movement_speed);
    }

    // idem
}

/*
void Player::updateCollision(const sf::RenderTarget *target)
{
}
*/

void Player::update(const sf::RenderTarget *target)
{
    // Collison
    // this->updateCollision(target);

    // Entrées clavier
    this->updateInput();
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
