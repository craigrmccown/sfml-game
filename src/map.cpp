#include "../include/map.hpp"

Map::Map(const TextureManager& texture_manager, EventBus& event_bus) : player(texture_manager)
{
	player.set_position(500, 500, 0);
	this->add_object(player);
	event_bus.subscribe(sf::Event::KeyPressed, this, &Map::handle_key_pressed);
}

void Map::draw(sf::RenderWindow& window, double elapsed_ms)
{
	for (auto i = this->indexed_objects.begin(); i != this->indexed_objects.end(); i++)
	{
		for (auto j = i->second.begin(); j != i->second.end(); j++)
		{
			j->get()->draw(window, elapsed_ms);
		}
	}
}

void Map::add_object(GameObject& game_object)
{
	int z_pos = game_object.get_z_pos();
	this->indexed_objects[z_pos].push_back(std::shared_ptr<GameObject>(&game_object));
}

void Map::handle_key_pressed(sf::Event event)
{
	switch (event.key.code)
	{
		case sf::Keyboard::Left:
		{
			this->player.apply_force(-1000, 0);
			break;
		}
		case sf::Keyboard::Right:
		{
			this->player.apply_force(1000, 0);
			break;
		}
		case sf::Keyboard::Space:
		{
			this->player.stop();
			break;
		}
	}
}
