#ifndef BST_H
#define BST_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class BST {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BST();  // Default constructor
    ~BST(); // Destructor to clean up nodes

    void insert(int value);
    void visualize(sf::RenderWindow& window);
};

#endif
