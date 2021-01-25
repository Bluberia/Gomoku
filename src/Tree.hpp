#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
#include <memory>
#include "Board.hpp"

class Node {

private:
    int _value;
    std::pair<int, int> _pos;    
    std::vector<std::shared_ptr<Node>> _children;
    Board _boardAtInstant = Board(0);
public:

    Node() = default;
    ~Node();
    Node(const std::shared_ptr<Node>& node);
    Node(int value, std::pair<int, int> pos);
    Node(int value, std::pair<int, int> pos, Board board);
    
    Node operator=(const Node& node);
   
    void setBoard(const Board& board);
    void setValue(int value);
    void setPos(int x, int y);
    void setPos(std::pair<int, int> pos);
    void setChild(const std::shared_ptr<Node>& child);
    void setChildren(const std::vector<std::shared_ptr<Node>>& children);

    int getValue() const;
    const Board getBoard() const;
    const std::pair<int, int>& getPos() const;
    const std::vector<std::shared_ptr<Node>>& getChildren() const;
    const std::shared_ptr<Node>& getNode(size_t node) const;

};

class Tree {
private:
    std::shared_ptr<Node> _root;

public:
    Tree();
    ~Tree() = default;

    const std::shared_ptr<Node>& getRoot();

    void insert(const std::shared_ptr<Node>& node);
    void insert(const std::shared_ptr<Node>& parent, const std::shared_ptr<Node>& node);
    std::shared_ptr<Node> search(); //Add value to search by
    void deleteTree();
};

#endif // !__TREE_HPP__
