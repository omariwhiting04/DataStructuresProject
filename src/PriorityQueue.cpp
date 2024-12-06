#include "PriorityQueue.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm> // For sorting

PriorityQueue::PriorityQueue() {}

void PriorityQueue::enqueue(int value, int priority) {
    data.emplace_back(priority, value); // Add the value with its priority
    std::sort(data.begin(), data.end(), std::greater<>()); // Sort by priority (highest first)
}

void PriorityQueue::dequeue() {
    if (!data.empty()) {
        data.erase(data.begin()); // Remove the highest-priority value
    } else {
        std::cerr << "Priority Queue is empty. Cannot dequeue.\n";
    }
}

void PriorityQueue::visualize(sf::RenderWindow& window) {
    window.clear();

    drawPriorityQueue(window);

    window.display();
}

void PriorityQueue::drawPriorityQueue(sf::RenderWindow& window) {
    if (data.empty()) return;

    const float boxWidth = 70.0f;
    const float boxHeight = 40.0f;
    const float horizontalSpacing = 80.0f;

    for (size_t i = 0; i < data.size(); ++i) {
        float xPos = 50 + i * (boxWidth + horizontalSpacing);
        float yPos = window.getSize().y / 2.0f;

        // Draw the rectangle for the queue element
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setFillColor(sf::Color::Magenta);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setPosition(xPos, yPos);
        window.draw(box);

        // Draw the value and priority inside the rectangle
        sf::Text valueText;
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Error loading font for priority queue visualization.\n";
            return;
        }

        valueText.setFont(font);
        valueText.setString(std::to_string(data[i].second) + " (P" + std::to_string(data[i].first) + ")");
        valueText.setCharacterSize(14);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(xPos + 5, yPos + 5);
        window.draw(valueText);
    }
}
