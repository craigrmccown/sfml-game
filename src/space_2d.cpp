#include "../include/space_2d.hpp"
#include <iostream>

Space2d::Space2dNode::Space2dNode(float left, float top, float width, float height)
{
    this->bounds = new sf::FloatRect(left, top, width, height);
    this->node1 = nullptr;
    this->node2 = nullptr;
    this->node3 = nullptr;
    this->node4 = nullptr;
}

void Space2d::Space2dNode::build_children()
{
    float child_width = this->bounds->width / 2;
    float child_height = this->bounds->height / 2;
    float center_x = this->bounds->left + child_width;
    float center_y = this->bounds->top + child_height;

    this->node1 = new Space2dNode(center_x, this->bounds->top, child_width, child_height);
    this->node2 = new Space2dNode(center_x, center_y, child_width, child_height);
    this->node3 = new Space2dNode(this->bounds->left, center_y, child_width, child_height);
    this->node4 = new Space2dNode(this->bounds->left, this->bounds->top, child_width, child_height);
}

Space2d::Space2dNode::~Space2dNode()
{
    delete this->bounds;
}

void Space2d::build(Space2dNode *node, int level, int levels)
{
    if (levels == level)
    {
        return;
    }

    node->build_children();

    build(node->node1, level + 1, levels);
    build(node->node2, level + 1, levels);
    build(node->node3, level + 1, levels);
    build(node->node4, level + 1, levels);
}

void Space2d::add(Space2dNode *node, sf::FloatRect bounds, GameObject *obj)
{
    if (!node->node1)
    {
        std::cout << "meh" << "\n";
        node->objs.push_back(obj);
        return;
    }

    std::cout << "add" << "\n";

    if (node->node1->bounds->intersects(bounds))
    {
        std::cout << "1" << "\n";
        this->add(node->node1, bounds, obj);
    }

    if (node->node2->bounds->intersects(bounds))
    {
        std::cout << "2" << "\n";
        this->add(node->node2, bounds, obj);
    }

    if (node->node3->bounds->intersects(bounds))
    {
        std::cout << "3" << "\n";
        this->add(node->node3, bounds, obj);
    }

    if (node->node4->bounds->intersects(bounds))
    {
        std::cout << "4" << "\n";
        this->add(node->node4, bounds, obj);
    }
}

std::vector<GameObject *> *Space2d::find(Space2dNode *node, sf::FloatRect bounds, std::vector<GameObject *> *objs)
{
    if (!node->node1)
    {
        objs->insert(objs->end(), node->objs.begin(), node->objs.end());
    }

    if (node->node1->bounds->intersects(bounds))
    {
        this->find(node->node1, bounds, objs);
    }

    if (node->node2->bounds->intersects(bounds))
    {
        this->find(node->node2, bounds, objs);
    }

    if (node->node3->bounds->intersects(bounds))
    {
        this->find(node->node3, bounds, objs);
    }

    if (node->node4->bounds->intersects(bounds))
    {
        return this->find(node->node4, bounds, objs);
    }

    return objs;
}

void Space2d::build(float left, float top, float width, float height, int levels)
{
    int level = 0;
    this->root = new Space2dNode(left, top, width, height);
    this->build(this->root, level, levels);
}

void Space2d::add(GameObject *obj)
{
    // TODO fix memory leak
    this->add(this->root, sf::FloatRect(obj->get_x_pos(), obj->get_y_pos(), obj->get_width(), obj->get_height()), obj);
}

std::vector<GameObject *> *Space2d::find(GameObject *obj)
{
    // TODO fix memory leak
    return this->find(this->root, sf::FloatRect(obj->get_x_pos(), obj->get_y_pos(), obj->get_width(), obj->get_height()), new std::vector<GameObject *>());
}

Space2d::~Space2d() {
    // TODO fix memory leak
}
