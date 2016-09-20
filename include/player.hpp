#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "game_object.hpp"
#include "texture_manager.hpp"

class Player : public GameObject
{

public:

    Player(TextureManager &texture_manager);
    void walk();
    void draw(sf::RenderWindow &window, int elapsed_ms);
};

#endif
