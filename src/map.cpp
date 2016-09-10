#include "../include/map.hpp"

Map::Map(int map_width, int num_tiles_x, int num_tiles_y)
{
    sf::Texture *grass_texture = new sf::Texture();
    sf::Texture *water_texture = new sf::Texture();

    this->textures.push_back(grass_texture);
    this->textures.push_back(water_texture);

    grass_texture->loadFromFile("assets/tile_grass.png");
    water_texture->loadFromFile("assets/tile_water.png");

    for(int y = 0; y < num_tiles_y; y ++)
    {
        for (int x = 0; x < num_tiles_x; x ++)
        {
            MapTile *tile;

            if ((x - y) % 5 > 1 || x + y < 5)
            {
                tile = new WaterTile(water_texture);
            }
            else
            {
                tile = new GrassTile(grass_texture);
            }

            int x_pos = (x - y - 1) * (MapTile::width / 2) + (map_width / 2);
            int y_pos = (x + y) * (MapTile::height / 2);

            tile->set_position(x_pos, y_pos);
            tiles.push_back(tile);
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
