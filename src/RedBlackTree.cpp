#include "RedBlackTree.h"
#include <SFML/Graphics.hpp>
#include <cmath>

RedBlackTree::RedBlackTree() : root(nullptr) {}

void RedBlackTree::insert(int value) {
    RBNode* newNode = new RBNode(value, RED);
    if (!root) {
        root = newNode;
        root->color = BLACK;
        return;
    }

    RBNode* current = root;
    RBNode* parent = nullptr;

    while (current) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    fixViolation(root, newNode);
}

void RedBlackTree::fixViolation(RBNode*& root, RBNode*& node) {
    RBNode* parent = nullptr;
    RBNode* grandparent = nullptr;

    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rightRotate(root, grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            RBNode* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                leftRotate(root, grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(RBNode*& root, RBNode*& node) {
    RBNode* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rightRotate(RBNode*& root, RBNode*& node) {
    RBNode* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RedBlackTree::visualize(sf::RenderWindow& window) {
    if (!root) {
        std::cerr << "Red-Black Tree is empty.\n"; // Debug message
        return;
    }

    std::cout << "Visualizing tree starting from root: " << root->value << "\n"; // Debug message

    float startX = window.getSize().x / 2.0f;
    float startY = 50.0f;
    float offset = 150.0f;

    drawNode(window, root, startX, startY, offset);
    window.display();
}


void RedBlackTree::drawNode(sf::RenderWindow& window, RBNode* node, float x, float y, float offset) {
    if (!node) return;

    std::cout << "Drawing node: " << node->value << " at (" << x << ", " << y << ")\n"; // Debug message
    // Draw the current node as a circle
    sf::CircleShape circle(20); // Node size
    circle.setFillColor(node->color == RED ? sf::Color::Red : sf::Color::Black);
    circle.setPosition(x - 20, y - 20); // Center the circle

    // Add text to the node
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font for Red-Black Tree visualization.\n";
        return;
    }
    text.setFont(font);
    text.setString(std::to_string(node->value));
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - 10, y - 10);

    // Draw the circle and text
    window.draw(circle);
    window.draw(text);

    // Draw lines connecting to children
    if (node->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(x - offset, y + 100)) // Position left child
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->left, x - offset, y + 100, offset / 2); // Recursive call
    }

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(x + offset, y + 100)) // Position right child
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->right, x + offset, y + 100, offset / 2); // Recursive call
    }
}
