#include "Player.hpp"
#include <cmath>
#include <iostream>

void Player::init_texture()
{
    // Load texture from file
    if (!this->texture.loadFromFile("../repository/data/textures/blob.png"))
    {
        std::cout << "ERROR::PLAYER::INIT_TEXTURE::Could not load texture file" << std::endl;
    }
}

void Player::init_sprite()
{
    // Set texture to the sprite
    this->sprite.setTexture(this->texture);

    // Resize the sprite
    this->sprite.scale(0.8f, 0.8f);
}

void Player::init_var()
{
    this->movement_speed = 5.f;
}

void Player::init_shape()
{
    // Acts as a hitbox
    this->shape.setFillColor(sf::Color::Transparent);
    this->shape.setSize(sf::Vector2f(40.f, 40.f));
}

Player::Player(float x, float y)
{
    this->shape.setPosition(x, y);
    this->init_texture();
    this->init_sprite();

    this->init_var();
    this->init_shape();
}

Player::~Player()
{
}

sf::Vector2f Player::getPosition() const
{
    return (this->shape.getPosition());
}

sf::Vector2f Player::getCenter() const
{
    sf::Vector2f C;
    C.x = this->getPosition().x + this->shape.getSize().x / 2;
    C.y = this->getPosition().y + this->shape.getSize().y / 2;
    return C;
}

sf::Vector2f Player::getDirectionToNearestEnemy(std::vector<Enemy> &enemies) const
{
    // Check if there are any enemies
    if (enemies.empty())
    {
        return {0.f, 0.f};
    }

    // Find the nearest enemy
    auto nearestEnemy = std::min_element(enemies.begin(), enemies.end(), [this](const Enemy &e1, const Enemy &e2)
                                         {
            // Calculate the distance from the player to each enemy
            auto distanceToE1 = std::sqrt(std::pow(e1.getPosition().x - this->getPosition().x, 2) + std::pow(e1.getPosition().y - this->getPosition().y, 2));
            auto distanceToE2 = std::sqrt(std::pow(e2.getPosition().x - this->getPosition().x, 2) + std::pow(e2.getPosition().y - this->getPosition().y, 2));

            return distanceToE1 < distanceToE2; });

    // Return the direction from the player to the nearest enemy
    return nearestEnemy->getPosition() - this->getPosition();
}

// Keyboard input
void Player::updateInput()
{
    // Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->shape.move(-this->movement_speed, 0.f);
        this->moveSprite(-this->movement_speed, 0.f);
    }

    // Right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movement_speed, 0.f);
        this->moveSprite(this->movement_speed, 0.f);
    }

    // else prevents opposite movement to occur (that would immobilize the Player)

    // Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->shape.move(0.f, -this->movement_speed);
        this->moveSprite(0.f, -this->movement_speed);
    }

    // Down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movement_speed);
        this->moveSprite(0.f, this->movement_speed);
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

    // Keyboard input
    this->updateInput();
}

void Player::moveSprite(const float dirX, const float dirY)
{
    this->sprite.move(dirX, dirY);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->sprite);
}
