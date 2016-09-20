#include "../include/player.hpp"

Player::Player(TextureManager &texture_manager) : GameObject(GameObject::base_width, GameObject::base_depth, GameObject::base_height)
{
    this->sprite.setTexture(texture_manager.get_texture("grass_tile"));
}

void Player::walk()
{
    this->x_vel = 4;
    this->x_acc = -3;
}

void Player::draw(sf::RenderWindow &window, int elapsed_ms)
{
    this->move(elapsed_ms);
    window.draw(this->sprite);
}
