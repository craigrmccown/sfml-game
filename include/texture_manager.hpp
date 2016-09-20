#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager
{
    std::map<std::string, sf::Texture> textures;

public:

    void load_texture(std::string key, std::string path);
    sf::Texture &get_texture(std::string key);
};

#endif
