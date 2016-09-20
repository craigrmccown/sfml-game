#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:

    sf::Sprite sprite;
    int depth;
    int width;
    int height;
    float x_pos = 0;
    float y_pos = 0;
    float z_pos = 0;
    float x_vel = 0;
    float y_vel = 0;
    float z_vel = 0;
    float x_acc = 0;
    float y_acc = 0;
    float z_acc = 0;

    float calc_dist(float vel, float acc, float sec);
    float calc_vel(float vel, float acc, float sec);

public:
    static const int base_width = 100;
    static const int base_depth = 50;
    static const int base_height = 25;
    
    GameObject(int depth, int width, int height);
    void set_position(float x, float y, float z);
    void move(int elapsed_ms);
    float get_width();
    float get_height();
    float get_x_pos();
    float get_y_pos();
    virtual void draw(sf::RenderWindow &window, int elapsed_ms) = 0;
};

#endif
