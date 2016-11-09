#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game_object.hpp"
#include "texture_manager.hpp"

class Player : public GameObject
{

public:

    Player(const TextureManager& texture_manager);
    void walk(int direction);
	void stop();
    void draw(sf::RenderWindow& window, double elapsed_ms);
};

#endif
