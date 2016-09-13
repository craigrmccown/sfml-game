#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "game_object.hpp"

class Player : public GameObject
{

public:

    Player(sf::Texture *texture);
    void walk();
    void draw(sf::RenderWindow *window, int elapsed_ms);
};

#endif
