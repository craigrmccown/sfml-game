#include "../include/space_2d.hpp"

Space2d::Space2dNode::Space2dNode(double left, double top, double width, double height) :
    bounds((float)left, (float)top, (float)width, (float)height)
{

}

void Space2d::Space2dNode::build_children()
{
    double child_width = this->bounds.width / 2;
    double child_height = this->bounds.height / 2;
    double center_x = this->bounds.left + child_width;
    double center_y = this->bounds.top + child_height;

    this->children.push_back(Space2dNode(center_x, this->bounds.top, child_width, child_height));
    this->children.push_back(Space2dNode(center_x, center_y, child_width, child_height));
    this->children.push_back(Space2dNode(this->bounds.left, center_y, child_width, child_height));
    this->children.push_back(Space2dNode(this->bounds.left, this->bounds.top, child_width, child_height));
}

Space2d::Space2d(double left, double top, double width, double height) :
    root(left, top, width, height)
{

}

void Space2d::build(Space2dNode &node, int level, int levels)
{
    if (level == levels)
    {
        return;
    }

    node.build_children();

    build(node.children[0], level + 1, levels);
    build(node.children[1], level + 1, levels);
    build(node.children[2], level + 1, levels);
    build(node.children[3], level + 1, levels);
}

void Space2d::add(Space2dNode& node, sf::FloatRect bounds, GameObject& obj)
{
    if (node.children.empty())
    {
        node.objs.push_back(std::shared_ptr<GameObject>(&obj));
        return;
    }

    if (node.children[0].bounds.intersects(bounds))
    {
        this->add(node.children[0], bounds, obj);
    }

    if (node.children[1].bounds.intersects(bounds))
    {
        this->add(node.children[1], bounds, obj);
    }

    if (node.children[2].bounds.intersects(bounds))
    {
        this->add(node.children[2], bounds, obj);
    }

    if (node.children[3].bounds.intersects(bounds))
    {
        this->add(node.children[3], bounds, obj);
    }
}

std::vector<std::shared_ptr<GameObject>> Space2d::find(Space2dNode& node, sf::FloatRect bounds, std::vector<std::shared_ptr<GameObject>> objs)
{
    if (node.children.empty())
    {
        objs.insert(objs.end(), node.objs.begin(), node.objs.end());
        return objs;
    }

    if (node.children[0].bounds.intersects(bounds))
    {
        this->find(node.children[0], bounds, objs);
    }

    if (node.children[1].bounds.intersects(bounds))
    {
        this->find(node.children[1], bounds, objs);
    }

    if (node.children[2].bounds.intersects(bounds))
    {
        this->find(node.children[2], bounds, objs);
    }

    if (node.children[3].bounds.intersects(bounds))
    {
        this->find(node.children[3], bounds, objs);
    }

    return objs;
}

void Space2d::build(int levels)
{
    this->build(this->root, 0, levels);
}

void Space2d::add(GameObject& obj)
{
    sf::FloatRect bounds;
    bounds = sf::FloatRect((float)obj.get_x_pos(), (float)obj.get_y_pos(), (float)obj.get_width(), (float)obj.get_height());
    this->add(this->root, std::move(bounds), obj);
}

std::vector<std::shared_ptr<GameObject>> Space2d::find(GameObject& obj)
{
    sf::FloatRect bounds;
    bounds = sf::FloatRect((float)obj.get_x_pos(), (float)obj.get_y_pos(), (float)obj.get_width(), (float)obj.get_height());
    return this->find(this->root, std::move(bounds), std::vector<std::shared_ptr<GameObject>>());
}
