#include "../include/player.hpp"

Player::Player(sf::Texture *texture) : GameObject(GameObject::base_width, GameObject::base_depth, GameObject::base_height)
{
    this->sprite.setTexture(*texture);
}

void Player::walk()
{
    this->x_vel = 4;
    this->x_acc = -3;
}

void Player::draw(sf::RenderWindow *window, int elapsed_ms)
{
    this->move(elapsed_ms);
    window->draw(this->sprite);
}
