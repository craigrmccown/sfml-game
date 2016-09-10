#include <SFML/Graphics.hpp>

class SpriteSheet
{
    sf::Texture *texture;
    int sprite_width;
    int sprite_height;

    public:

    SpriteSheet(sf::Texture *texture, int sprite_width, int sprite_height)
    {
        this->texture = texture;
        this->sprite_width = sprite_width;
        this->sprite_height = sprite_height;
    }

    int set_texture(sf::Sprite *sprite, int x, int y)
    {
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(x * this->sprite_width, y * this->sprite_height, sprite_width, sprite_height));
    }
};

class Animation
{
    SpriteSheet *sprite_sheet;
    int sprite_sheet_y;
    int sprite_sheet_x;
    int num_frames;
    int current_elapsed;
    int ms_per_frame;

    public:

    sf::Texture *current_texture;

    Animation(SpriteSheet *sprite_sheet, int sprite_sheet_y, int num_frames, int duration_ms)
    {
        this->sprite_sheet = sprite_sheet;
        this->sprite_sheet_y = sprite_sheet_y;
        this->num_frames = num_frames;
        this->current_elapsed = 0;
        this->sprite_sheet_x = 0;
        this->ms_per_frame = (int)(1.0 * duration_ms / num_frames);
    }

    void step(int elapsed_ms)
    {
        this->current_elapsed += elapsed_ms;
        int frames_elapsed = this->current_elapsed / this->ms_per_frame;

        if (frames_elapsed > 0)
        {
            this->current_elapsed = this->current_elapsed % this->ms_per_frame;
            this->sprite_sheet_x = (this->sprite_sheet_x + frames_elapsed) % this->num_frames;
        }
    }

    void draw(sf::Sprite *sprite)
    {
        sprite_sheet->set_texture(sprite, this->sprite_sheet_x, this->sprite_sheet_y);
    }
};

class GameObject
{
    protected:

    sf::Sprite sprite;

    public:

    GameObject() { }

    void set_position(int pos_x, int pos_y)
    {
        this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    }

    void move(float delta_x, float delta_y)
    {
        this->sprite.move(delta_x, delta_y);
    }

    int get_width()
    {
        this->sprite.getTextureRect().width;
    }

    int get_height()
    {
        this->sprite.getTextureRect().height;
    }

    virtual void draw(sf::RenderWindow *window, int elapsed_ms) = 0;
};

class GrassTile : public GameObject
{
    public:

    GrassTile(sf::Texture *texture)
    {
        this->sprite.setTexture(*texture);
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        window->draw(this->sprite);
    }
};

class WaterTile : public GameObject
{
    SpriteSheet *sprite_sheet;
    Animation *animation;

    public:

    WaterTile(sf::Texture *texture)
    {
        this->sprite_sheet = new SpriteSheet(texture, 100, 50);
        this->animation = new Animation(this->sprite_sheet, 0, 4, 1000);
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        this->animation->step(elapsed_ms);
        this->animation->draw(&this->sprite);
        window->draw(this->sprite);
    }

    ~WaterTile()
    {
        delete this->sprite_sheet;
        delete this->animation;
    }
};

class Map
{
    int num_tiles_y;
    int num_tiles_x;
    std::vector<GameObject *> tiles;
    std::vector<sf::Texture *> textures;
    std::vector<Animation *> animations;

    public:

    Map(int map_width, int num_tiles_x, int num_tiles_y)
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
                GameObject *tile;

                if ((x - y) % 5 > 1 || x + y < 5)
                {
                    tile = new WaterTile(water_texture);
                }
                else
                {
                    tile = new GrassTile(grass_texture);
                }

                int x_pos = (x - y - 1) * (tile->get_width() / 2) + (map_width / 2);
                int y_pos = (x + y) * (tile->get_height() / 2);
                tile->set_position(x_pos, y_pos);
                tiles.push_back(tile);
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
    Map map = Map(window_width, 25, 25);

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
