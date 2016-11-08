#include "../include/game_object.hpp"

double GameObject::calc_dist(double vel, double acc, double sec)
{
    return vel * sec + acc * sec * sec / 2;
}

double GameObject::calc_vel(double vel, double acc, double sec)
{
    return vel + acc * sec;
}

double GameObject::calc_acc(double force)
{
    return force / this->mass;
}

GameObject::GameObject(int width, int height, double mass)
{
    this->width = width;
    this->height = height;
    this->mass = mass;

    this->sprite.setOrigin(sf::Vector2f((float)(width / 2), (float)height));
}

GameObject::GameObject(int width, int height)
    : GameObject::GameObject(width, height, this->base_mass) { }

void GameObject::set_position(double x, double y, int z)
{
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;

    this->sprite.setPosition(sf::Vector2f((float)this->x_pos, (float)this->y_pos));
}

void GameObject::apply_force(double x_magnitude, double y_magnitude)
{
    this->x_forces.push_back(x_magnitude);
    this->y_forces.push_back(y_magnitude);
}

void GameObject::move(double elapsed_ms)
{
    double elapsed_s = 1.0f * elapsed_ms / 1000;
    double x_delta = this->calc_dist(this->x_vel, this->x_acc, elapsed_s);
    double y_delta = this->calc_dist(this->y_vel, this->y_acc, elapsed_s);
    this->x_vel = this->calc_vel(this->x_vel, this->x_acc, elapsed_s);
    this->y_vel = this->calc_vel(this->y_vel, this->y_acc, elapsed_s);

    double x_net_force = std::accumulate(this->x_forces.begin(), this->x_forces.end(), 0.0);
    double y_net_force = std::accumulate(this->y_forces.begin(), this->y_forces.end(), 0.0);

    this->x_acc = this->calc_acc(x_net_force);
    this->y_acc = this->calc_acc(y_net_force);

    this->set_position(this->x_pos + x_delta, this->y_pos + y_delta, this->z_pos);

    this->x_forces.clear();
    this->y_forces.clear();
}

double GameObject::get_width() const { return this->width; }
double GameObject::get_height() const { return this->height; }
double GameObject::get_x_pos() const { return this->x_pos; }
double GameObject::get_y_pos() const { return this->y_pos; }
int GameObject::get_z_pos() const { return this->z_pos; }
