#include "../include/player.hpp"

Player::Player(const TextureManager& texture_manager) : GameObject(GameObject::base_width, GameObject::base_height)
{
    this->sprite.setTexture(texture_manager.get_texture("player"));
    this->sprite.setScale(100/this->sprite.getLocalBounds().width, 100/this->sprite.getLocalBounds().height);
}

void Player::walk(int direction)
{
	if (direction >= 0)
	{
		this->x_vel = 140;
		this->x_acc = -20;
	}
	else 
	{
		this->x_vel = -140;
		this->x_acc = 20;
	}
}

void Player::stop()
{
	this->x_vel = 0;
}

void Player::draw(sf::RenderWindow& window, double elapsed_ms)
{
    this->move(elapsed_ms);
	window.draw(this->sprite);
}
