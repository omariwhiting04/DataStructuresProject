#ifndef BTREE_H
#define BTREE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class BTree {
public:
    BTree(int t); // Constructor: t is the minimum degree
    void insert(int key);
    void visualize(sf::RenderWindow& window);

private:
    struct Node {
        bool isLeaf;
        std::vector<int> keys;
        std::vector<Node*> children;
        Node(bool leaf) : isLeaf(leaf) {}
    };

    Node* root;
    int t; // Minimum degree
    void insertNonFull(Node* node, int key);
    void splitChild(Node* parent, int i, Node* child);
    void drawNode(sf::RenderWindow& window, Node* node, float x, float y, float horizontalSpacing);

    const float nodeRadius = 20.0f;
    const float verticalSpacing = 60.0f;
};

#endif // BTREE_H
