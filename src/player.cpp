#include "../include/player.hpp"

Player::Player(const TextureManager& texture_manager) : GameObject(GameObject::base_width, GameObject::base_height, 3)
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
	/* if the mouse is inside of the object */
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (mousePos.x >= this->get_x_pos() - this->get_width() / 2
		&& mousePos.x <= this->get_x_pos() + this->get_width() / 2
		&& mousePos.y <= this->get_y_pos()
		&& mousePos.y >= this->get_y_pos() - this->get_height())
	{
		if (mousePos.x <= this->get_x_pos() + this->get_width() / 2
			&& mousePos.x >= this->get_x_pos())
		{
			this->apply_force(-3000, 0);
		}
		else
		{
			this->apply_force(3000, 0);
		}

		if (mousePos.y <= this->get_y_pos() - this->get_height() / 2)
		{
			this->apply_force(0, 3000);
		}
		else
		{
			this->apply_force(0, -3000);
		}
	}

    this->move(elapsed_ms);
	window.draw(this->sprite);
}
