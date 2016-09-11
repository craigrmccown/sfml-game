#include "../include/map.hpp"

Map::Map(int map_width, int num_tiles_x, int num_tiles_y)
{
    this-> map_width = map_width;

    sf::Texture *grass_texture = new sf::Texture();
    sf::Texture *water_texture = new sf::Texture();

    this->textures.push_back(grass_texture);
    this->textures.push_back(water_texture);

    grass_texture->loadFromFile("assets/tile_grass.png");
    water_texture->loadFromFile("assets/tile_water.png");

    for (int z = 0; z < 2; z ++)
    {
        for (int y = 0; y < num_tiles_y; y ++)
        {
            for (int x = 0; x < num_tiles_x; x ++)
            {
                if (z == 0)
                {
                    MapTile *tile = new GrassTile(grass_texture);
                    tile->set_position(x, y, z);
                    tiles.push_back(tile);
                }
                else if (z + x + y >= 9 && z + y + x <= 20)
                {
                    MapTile *tile = new GrassTile(grass_texture);
                    tile->set_position(x, y, z);
                    tiles.push_back(tile);
                }
            }
        }
    }
}

void Map::draw(sf::RenderWindow *window, int elapsed_ms)
{
    for (int i = 0; i < tiles.size(); i ++)
    {
        tiles[i]->draw(window, elapsed_ms);
    }
}

Map::~Map()
{
    int i;

    for (int i = 0; i < tiles.size(); i ++)
    {
        delete tiles[i];
    }

    for (int i = 0; i < textures.size(); i ++)
    {
        delete textures[i];
    }
}
