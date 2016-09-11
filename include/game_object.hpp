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
    static const int tile_width = 100;
    static const int tile_depth = 50;
    static const int tile_height = 25;

    GameObject(int depth, int width, int height);
    void set_position(float x, float y, float z);
    virtual void draw(sf::RenderWindow *window, int elapsed_ms) = 0;
};

#endif
