#include "BTree.h"
#include <SFML/Graphics.hpp>
#include <cmath>

BTree::BTree(int t) : t(t), root(nullptr) {}

void BTree::insert(int key) {
    if (!root) {
        root = new Node(true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            Node* newRoot = new Node(false);
            newRoot->children.push_back(root);
            splitChild(newRoot, 0, root);
            root = newRoot;
        }
        insertNonFull(root, key);
    }
}

void BTree::insertNonFull(Node* node, int key) {
    int i = node->keys.size() - 1;
    if (node->isLeaf) {
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {
        while (i >= 0 && key < node->keys[i]) i--;
        i++;
        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) i++;
        }
        insertNonFull(node->children[i], key);
    }
}

void BTree::splitChild(Node* parent, int i, Node* child) {
    Node* newChild = new Node(child->isLeaf);
    for (int j = 0; j < t - 1; ++j) {
        newChild->keys.push_back(child->keys[j + t]);
    }
    if (!child->isLeaf) {
        for (int j = 0; j < t; ++j) {
            newChild->children.push_back(child->children[j + t]);
        }
    }
    child->keys.resize(t - 1);
    parent->children.insert(parent->children.begin() + i + 1, newChild);
    parent->keys.insert(parent->keys.begin() + i, child->keys[t - 1]);
}

void BTree::visualize(sf::RenderWindow& window) {
    if (root) drawNode(window, root, window.getSize().x / 2, 50, 150);
}

void BTree::drawNode(sf::RenderWindow& window, Node* node, float x, float y, float horizontalSpacing) {
    sf::CircleShape circle(nodeRadius);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(x - nodeRadius, y - nodeRadius);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font.\n";
        return;
    }

    for (size_t i = 0; i < node->keys.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(node->keys[i]));
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + i * 20 - nodeRadius, y - 10);
        window.draw(circle);
        window.draw(text);
    }

    if (!node->isLeaf) {
        for (size_t i = 0; i <= node->keys.size(); ++i) {
            float childX = x + (i - node->keys.size() / 2.0f) * horizontalSpacing;
            float childY = y + verticalSpacing;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
                sf::Vertex(sf::Vector2f(childX, childY), sf::Color::White)
            };

            window.draw(line, 2, sf::Lines);
            drawNode(window, node->children[i], childX, childY, horizontalSpacing / 2);
        }
    }
}
