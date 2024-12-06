#include "Heap.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Constructor
Heap::Heap() {
    // No specific initialization required in this version
}

// Inserts an element into the heap
void Heap::insert(int value) {
    data.push_back(value); // Add the new value at the end
    int currentIndex = data.size() - 1;
    int parentIndex = (currentIndex - 1) / 2;

    // Heapify-up
    while (currentIndex > 0 && data[currentIndex] > data[parentIndex]) {
        std::swap(data[currentIndex], data[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

// Removes the root element from the heap
void Heap::remove() {
    if (data.empty()) return;

    // Replace root with the last element
    data[0] = data.back();
    data.pop_back();

    // Heapify-down
    int currentIndex = 0;
    while (true) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        int largest = currentIndex;

        if (leftChild < data.size() && data[leftChild] > data[largest]) {
            largest = leftChild;
        }
        if (rightChild < data.size() && data[rightChild] > data[largest]) {
            largest = rightChild;
        }
        if (largest == currentIndex) break;

        std::swap(data[currentIndex], data[largest]);
        currentIndex = largest;
    }
}

// Visualizes the heap on the SFML window
void Heap::visualize(sf::RenderWindow& window) {
    window.clear();
    drawHeap(window);
    window.display();
}

// Draws the heap nodes and connections
void Heap::drawHeap(sf::RenderWindow& window) {
    if (data.empty()) return;

    const float nodeRadius = 20.0f;
    const float horizontalSpacing = 50.0f;
    const float verticalSpacing = 60.0f;

    for (size_t i = 0; i < data.size(); ++i) {
        int level = std::log2(i + 1); // Determine the level of the node
        float xPos = window.getSize().x / 2.0f + (i - (std::pow(2, level) - 1)) * horizontalSpacing / (level + 1);
        float yPos = 50 + level * verticalSpacing;

        sf::CircleShape node(nodeRadius);
        node.setFillColor(sf::Color::Blue);
        node.setPosition(xPos - nodeRadius, yPos - nodeRadius);

        sf::Text valueText;
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Error loading font for heap visualization.\n";
            return;
        }
        valueText.setFont(font);
        valueText.setString(std::to_string(data[i]));
        valueText.setCharacterSize(16);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(xPos - nodeRadius / 2, yPos - nodeRadius / 2);

        window.draw(node);
        window.draw(valueText);

        // Draw connections to children
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < data.size()) {
            int leftLevel = std::log2(leftChild + 1);
            float leftXPos = window.getSize().x / 2.0f + (leftChild - (std::pow(2, leftLevel) - 1)) * horizontalSpacing / (leftLevel + 1);
            float leftYPos = 50 + leftLevel * verticalSpacing;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::White),
                sf::Vertex(sf::Vector2f(leftXPos, leftYPos), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
        }

        if (rightChild < data.size()) {
            int rightLevel = std::log2(rightChild + 1);
            float rightXPos = window.getSize().x / 2.0f + (rightChild - (std::pow(2, rightLevel) - 1)) * horizontalSpacing / (rightLevel + 1);
            float rightYPos = 50 + rightLevel * verticalSpacing;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::White),
                sf::Vertex(sf::Vector2f(rightXPos, rightYPos), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
        }
    }
}
