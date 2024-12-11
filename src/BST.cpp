#include "BST.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

BST::BST() : root(nullptr) {
    // Default constructor
}

BST::~BST() {
    // Clean up the tree
    std::function<void(Node*)> deleteTree = [&](Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);
}

void BST::insert(int value) {
    std::function<void(Node*&, int)> insertNode = [&](Node*& node, int val) {
        if (!node) {
            node = new Node(val);
            return;
        }
        if (val < node->value) {
            insertNode(node->left, val);
        } else {
            insertNode(node->right, val);
        }
    };
    insertNode(root, value);
}

void BST::visualize(sf::RenderWindow& window) {
    if (!root) {
        std::cout << "BST is empty, nothing to visualize.\n";
        return;
    }

    window.clear(sf::Color::Black);

    const float nodeRadius = 20.0f;
    const float verticalSpacing = 60.0f;
    const float horizontalSpacing = 100.0f;

    std::function<void(Node*, float, float, float)> drawNode = [&](Node* node, float x, float y, float offset) {
        if (!node) return;

        // Draw the node
        sf::CircleShape shape(nodeRadius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x - nodeRadius, y - nodeRadius);
        window.draw(shape);

        // Draw the value in the node
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Error loading font for BST visualization.\n";
            return;
        }

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(node->value));
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::White);
        text.setPosition(x - nodeRadius / 2, y - nodeRadius / 2);
        window.draw(text);

        // Draw connections to children
        if (node->left) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
                sf::Vertex(sf::Vector2f(x - offset, y + verticalSpacing), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->left, x - offset, y + verticalSpacing, offset / 2);
        }

        if (node->right) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
                sf::Vertex(sf::Vector2f(x + offset, y + verticalSpacing), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->right, x + offset, y + verticalSpacing, offset / 2);
        }
    };

    drawNode(root, window.getSize().x / 2, 50, 150);

    window.display();
}
