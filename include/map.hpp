#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game_object.hpp"
#include "event_bus.hpp"
#include "player.hpp"
#include "texture_manager.hpp"

class Map
{
    std::vector<std::shared_ptr<GameObject>> objects;
	std::map<int, std::vector<std::shared_ptr<GameObject>>> indexed_objects;
	Player player;

public:
	Map(const TextureManager& texture_manager, EventBus& event_bus);
    void draw(sf::RenderWindow& window, double elapsed_ms);
	void add_object(GameObject& object);
	void handle_key_pressed(sf::Event event);
};

#endif
