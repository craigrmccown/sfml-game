#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SFML/Graphics>

class GameObject
{
protected:

    sf::Sprite sprite;

public:

    void set_position(int pos_x, int pos_y);
    void move(float delta_x, float delta_y);
    virtual void draw(sf::RenderWindow *window, int elapsed_ms) = 0;
}

#endif
