#include "../include/game_object.hpp"

float GameObject::calc_dist(float vel, float acc, float sec)
{
    return vel * sec + acc * sec * sec / 2;
}

float GameObject::calc_vel(float vel, float acc, float sec)
{
    return vel + acc * sec;
}

GameObject::GameObject(int width, int depth, int height)
{
    this->width = width;
    this->depth = depth;
    this->height = height;

    this->sprite.setOrigin(sf::Vector2f(width / 2, height + depth / 2));
}

void GameObject::set_position(float x, float y, float z)
{
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;

    int x_pos = (int)((x - y) * (GameObject::base_width / 2));
    int y_pos = (int)((x + y) * (GameObject::base_depth / 2) - (GameObject::base_height * z));
    this->sprite.setPosition(sf::Vector2f(x_pos, y_pos));
}

void GameObject::move(int elapsed_ms)
{
    float elapsed_s = 1.0f * elapsed_ms / 1000;
    float x_delta = this->calc_dist(this->x_vel, this->x_acc, elapsed_s);
    float y_delta = this->calc_dist(this->y_vel, this->y_acc, elapsed_s);
    float z_delta = this->calc_dist(this->z_vel, this->z_acc, elapsed_s);
    this->x_vel = this->calc_vel(this->x_vel, this->x_acc, elapsed_s);
    this->y_vel = this->calc_vel(this->y_vel, this->y_acc, elapsed_s);
    this->z_vel = this->calc_vel(this->z_vel, this->z_acc, elapsed_s);

    this->set_position(this->x_pos + x_delta, this->y_pos + y_delta, this->z_pos + z_delta);
}

float GameObject::get_width() const { return 1; }
float GameObject::get_height() const { return 1; }
float GameObject::get_x_pos() const { return this->x_pos; }
float GameObject::get_y_pos() const { return this->y_pos; }
