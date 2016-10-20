#include "../include/player.hpp"

Player::Player(const TextureManager& texture_manager) : GameObject(GameObject::base_width, GameObject::base_depth, GameObject::base_height)
{
    this->sprite.setTexture(texture_manager.get_texture("player"));
}

void Player::walk()
{
    this->x_vel = 8;
    this->x_acc = -5;
}

void Player::draw(sf::RenderWindow& window, double elapsed_ms)
{
    this->move(elapsed_ms);
    window.draw(this->sprite);
}
