#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject
{
protected:

    sf::Sprite sprite;
    int depth;
    int width;
    int height;

public:
    static const int base_width = 100;
    static const int base_depth = 50;
    static const int base_height = 25;

    GameObject(int depth, int width, int height);
    void set_position(float x, float y, float z);
    void set_color(int color);
    virtual void draw(sf::RenderWindow *window, int elapsed_ms) = 0;
};

#endif
