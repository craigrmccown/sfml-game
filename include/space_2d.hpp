#ifndef SPACE_2D
#define SPACE_2D

#include <memory>
#include <SFML/Graphics.hpp>
#include "game_object.hpp"

class Space2d
{
    class Space2dNode
    {

    public:

        sf::FloatRect bounds;
        std::vector<std::shared_ptr<GameObject>> objs;
        std::vector<Space2dNode> children;

        Space2dNode(float left, float top, float width, float height);
        void build_children();
    };

    Space2dNode root;
    void build(Space2dNode& node, int level, int levels);
    void add(Space2dNode& node, sf::FloatRect bounds, GameObject& obj);
    std::vector<std::shared_ptr<GameObject>> find(Space2dNode& node, sf::FloatRect bounds, std::vector<std::shared_ptr<GameObject>> objs);

public:

    Space2d(float left, float top, float width, float height);
    void build(int levels);
    void add(GameObject& obj);
    std::vector<std::shared_ptr<GameObject>> find(GameObject& obj);
};

#endif
