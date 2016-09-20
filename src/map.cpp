#include "../include/map.hpp"

Map::Map(TextureManager &texture_manager, int num_tiles_x, int num_tiles_y)
{
    for (int z = 0; z < 1; z ++)
    {
        for (int y = 0; y < num_tiles_y; y ++)
        {
            for (int x = 0; x < num_tiles_x; x ++)
            {
                std::unique_ptr<MapTile> tile = std::unique_ptr<MapTile>(new GrassTile(texture_manager));
                tile->set_position(x, y, z);
                this->tiles.push_back(std::move(tile));
            }
        }
    }
}

void Map::draw(sf::RenderWindow &window, int elapsed_ms)
{
    for (int i = 0; i < tiles.size(); i ++)
    {
        tiles[i]->draw(window, elapsed_ms);
    }
}
