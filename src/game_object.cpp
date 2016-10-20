#include "../include/game_object.hpp"

double GameObject::calc_dist(double vel, double acc, double sec)
{
    return vel * sec + acc * sec * sec / 2;
}

double GameObject::calc_vel(double vel, double acc, double sec)
{
    return vel + acc * sec;
}

GameObject::GameObject(int width, int depth, int height)
{
    this->width = width;
    this->depth = depth;
    this->height = height;

    this->sprite.setOrigin(sf::Vector2f((float)(width / 2), (float)(height + depth / 2)));
}

void GameObject::set_position(double x, double y, int z)
{
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;

    int x_pos = (int)((x - y) * (GameObject::base_width / 2));
    int y_pos = (int)((x + y) * (GameObject::base_depth / 2) - (GameObject::base_height * z));
    this->sprite.setPosition(sf::Vector2f((float)x_pos, (float)y_pos));
}

void GameObject::move(double elapsed_ms)
{
    double elapsed_s = 1.0f * elapsed_ms / 1000;
    double x_delta = this->calc_dist(this->x_vel, this->x_acc, elapsed_s);
    double y_delta = this->calc_dist(this->y_vel, this->y_acc, elapsed_s);
    this->x_vel = this->calc_vel(this->x_vel, this->x_acc, elapsed_s);
    this->y_vel = this->calc_vel(this->y_vel, this->y_acc, elapsed_s);

    this->set_position(this->x_pos + x_delta, this->y_pos + y_delta, this->z_pos);
}

double GameObject::get_width() const { return 1; }
double GameObject::get_height() const { return 1; }
double GameObject::get_x_pos() const { return this->x_pos; }
double GameObject::get_y_pos() const { return this->y_pos; }
