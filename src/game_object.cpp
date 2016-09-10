#include "include/game_object.hpp"

class GameObject
{
protected:

    sf::Sprite sprite;

public:

    void set_position(int pos_x, int pos_y)
    {
        this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    }

    void move(float delta_x, float delta_y)
    {
        this->sprite.move(delta_x, delta_y);
    }

    virtual void draw(sf::RenderWindow *window, int elapsed_ms) = 0;
};
