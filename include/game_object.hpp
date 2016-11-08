#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <memory>
#include <numeric>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:

    sf::Sprite sprite;

    int width;
    int height;
    double mass;

    double x_pos = 0;
    double y_pos = 0;
    int z_pos = 0;

    double x_vel = 0;
    double y_vel = 0;

    double x_acc = 0;
    double y_acc = 0;

    std::vector<int> x_forces;
    std::vector<int> y_forces;

    double calc_dist(double vel, double acc, double sec);
    double calc_vel(double vel, double acc, double sec);
    double calc_acc(double force);

public:
    static const int base_width = 100;
    static const int base_height = 100;
    static const int base_mass = 10;
    
    GameObject(int width, int height, double mass);
    GameObject(int width, int height);
    void set_position(double x, double y, int z);
    void apply_force(double x_magnitude, double y_magnitude);
    void move(double elapsed_ms);
    double get_width() const;
    double get_height() const;
    double get_x_pos() const;
    double get_y_pos() const;
	int get_z_pos() const;
    virtual void draw(sf::RenderWindow& window, double elapsed_ms) = 0;
};

#endif
