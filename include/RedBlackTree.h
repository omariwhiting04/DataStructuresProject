#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum Color { RED, BLACK }; // Define node colors

struct RBNode {
    int value;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int value, Color color) 
        : value(value), color(color), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;

    void leftRotate(RBNode*& root, RBNode*& node);
    void rightRotate(RBNode*& root, RBNode*& node);
    void fixViolation(RBNode*& root, RBNode*& node);
    void drawNode(sf::RenderWindow& window, RBNode* node, float x, float y, float offset);

public:
    RedBlackTree();
    void insert(int value); // Insert a value into the tree
    void visualize(sf::RenderWindow& window); // Visualize the tree
};

#endif
