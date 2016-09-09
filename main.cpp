#include <SFML/Graphics.hpp>

class Animation
{
    std::vector<sf::Texture *> textures;
    sf::Sprite *sprite;
    int current_elapsed;
    int texture_index;

    public:

    static const int ms_per_frame = 500;
    sf::Texture *current_texture;

    Animation()
    {
        this->current_elapsed = 0;
        this->texture_index = 0;
    }

    void set_sprite(sf::Sprite *sprite)
    {
        this->sprite = sprite;
    }

    void add_texture(sf::Texture *texture)
    {
        this->textures.push_back(texture);
    }

    void step(int elapsed_ms)
    {
        this->current_elapsed += elapsed_ms;
        int frames_elapsed = this->current_elapsed / Animation::ms_per_frame;

        if (frames_elapsed > 0)
        {
            this->current_elapsed = this->current_elapsed % Animation::ms_per_frame;
            this->texture_index = (this->texture_index + 1) % this->textures.size();
        }

        this->sprite->setTexture(*this->textures[this->texture_index]);
    }
};

class GameTile
{
    sf::Sprite sprite;
    Animation *animation; 

    public:

    static const int tile_width = 100;
    static const int tile_height = 50;

    GameTile(Animation *animation, int map_width, int x, int y)
    {
        this->animation = animation;
        this->animation->set_sprite(&this->sprite);

        int abs_x = (map_width / 2) + (GameTile::tile_width / 2) * (x - y - 1);
        int abs_y = (GameTile::tile_height / 2) * (x + y);
        this->sprite.setPosition(sf::Vector2f(abs_x, abs_y));
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        this->animation->step(elapsed_ms);
        window->draw(sprite);
    }
};

class Map
{
    int num_tiles_y;
    int num_tiles_x;
    std::vector<GameTile *> tiles;
    std::vector<sf::Texture *> textures;
    std::vector<Animation *> animations;

    public:

    Map(const int map_width)
    {
        this->num_tiles_y = this->num_tiles_x = (map_width / 2) / (GameTile::tile_width / 2);

        sf::Texture *grass_texture = new sf::Texture();
        sf::Texture *water_texture_0 = new sf::Texture();
        sf::Texture *water_texture_1 = new sf::Texture();

        this->textures.push_back(grass_texture);
        this->textures.push_back(water_texture_0);
        this->textures.push_back(water_texture_1);

        grass_texture->loadFromFile("assets/tile_grass.png");
        water_texture_0->loadFromFile("assets/tile_water_0.png");
        water_texture_1->loadFromFile("assets/tile_water_1.png");

        
        for(int y = 0; y < num_tiles_y; y ++)
        {
            for (int x = 0; x < num_tiles_x; x ++)
            {
                if ((x - y) % 5 > 1 || x + y < 5)
                {
                    Animation *water_animation = new Animation();
                    water_animation->add_texture(water_texture_0);
                    water_animation->add_texture(water_texture_1);
                    this->animations.push_back(water_animation);

                    tiles.push_back(new GameTile(water_animation, map_width, x, y));
                }
                else
                {
                    Animation *grass_animation = new Animation();
                    grass_animation->add_texture(grass_texture);
                    this->animations.push_back(grass_animation);

                    tiles.push_back(new GameTile(grass_animation, map_width, x, y));
                }
            }
        }
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        for (int i = 0; i < tiles.size(); i ++)
        {
            tiles[i]->draw(window, elapsed_ms);
        }
    }

    ~Map()
    {
        int i;

        for (i = 0; i < tiles.size(); i ++)
        {
            delete tiles[i];
        }

        for (i = 0; i < textures.size(); i ++)
        {
            delete textures[i];
        }

        for (i = 0; i < animations.size(); i ++)
        {
            delete animations[i];
        }
    }
};

int main()
{
    const int window_width = 1500;
    const int window_height = window_width / 2;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My Window");
    Map map = Map(window_width);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        map.draw(&window, elapsed.asMilliseconds());
        window.display();
    }

    return 0;
}
