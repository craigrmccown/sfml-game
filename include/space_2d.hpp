#ifndef SPACE_2D
#define SPACE_2D

#include <SFML/Graphics.hpp>
#include "game_object.hpp"

class Space2d
{
    class Space2dNode
    {

    public:

        sf::FloatRect *bounds;
        std::vector<GameObject *> objs;
        Space2dNode *node1;
        Space2dNode *node2;
        Space2dNode *node3;
        Space2dNode *node4;

        Space2dNode(float left, float top, float width, float height);
        void build_children();
        ~Space2dNode();
    };

    Space2dNode *root;
    void build(Space2dNode *node, int level, int levels);
    void add(Space2dNode *node, sf::FloatRect bounds, GameObject *obj);
    std::vector<GameObject *> *find(Space2dNode *node, sf::FloatRect bounds, std::vector<GameObject *> *objs);

public:

    void build(float left, float top, float width, float height, int levels);
    void add(GameObject *obj);
    std::vector<GameObject *> *find(GameObject *obj);
    ~Space2d();
    
};

#endif
