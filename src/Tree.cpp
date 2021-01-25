#include "Tree.hpp"
#include <utility>

Node::~Node()
{
}

Node::Node(const std::shared_ptr<Node>& node)
{
    this->setPos(node->getPos());
    this->setValue(node->getValue());
}

Node::Node(int value, std::pair<int, int> pos) : _value(value), _pos(pos)
{

}

Node::Node(int value, std::pair<int, int> pos, Board board) : _value(value), _pos(pos), _boardAtInstant(board)
{
}

Node Node::operator=(const Node& node)
{
    return Node(node);
}

void Node::setBoard(const Board& board)
{
    _boardAtInstant = board;
}

void Node::setValue(int value)
{
    _value = value;
}

void Node::setPos(int x, int y)
{
    _pos = std::make_pair(x, y);
}

void Node::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

void Node::setChild(const std::shared_ptr<Node>& child)
{
    _children.emplace_back(child);
}

void Node::setChildren(const std::vector<std::shared_ptr<Node>>& children)
{
    _children = children;
}

int Node::getValue() const
{
    return _value;
}

const Board Node::getBoard() const
{
    return _boardAtInstant;
}

const std::pair<int, int>& Node::getPos() const 
{
    return _pos;
}

const std::vector<std::shared_ptr<Node>>& Node::getChildren() const
{
    return _children;
}

const std::shared_ptr<Node>& Node::getNode(size_t node) const
{
    return _children.at(node);
}

Tree::Tree()
{
    _root = std::make_shared<Node>(0, std::make_pair(0, 0));
}

const std::shared_ptr<Node>& Tree::getRoot()
{
    return _root;
}

void Tree::insert(const std::shared_ptr<Node>& node)
{
    if (_root != nullptr)
        _root->setChild(node);
    else
        _root = std::make_shared<Node>(node);
}

void Tree::insert(const std::shared_ptr<Node>& parent, const std::shared_ptr<Node>& node)
{
    parent->setChild(node);
}

std::shared_ptr<Node> Tree::search()
{
    return std::make_shared<Node>();
}

void Tree::deleteTree()
{
}
