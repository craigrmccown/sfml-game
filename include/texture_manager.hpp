#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager
{
    std::map<std::string, sf::Texture> textures;

public:

    void load_texture(const std::string& key, const std::string& path);
    const sf::Texture& get_texture(const std::string& key) const;
};

#endif
