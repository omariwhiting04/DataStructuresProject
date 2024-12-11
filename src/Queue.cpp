#include "Queue.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

Queue::Queue() {}

void Queue::enqueue(int value) {
    data.push_back(value); // Add value to the queue
}

void Queue::dequeue() {
    if (!data.empty()) {
        data.erase(data.begin()); // Remove the front value
    } else {
        std::cerr << "Queue is empty. Cannot dequeue.\n";
    }
}

void Queue::visualize(sf::RenderWindow& window) {
    window.clear();

    drawQueue(window);

    window.display();
}

void Queue::drawQueue(sf::RenderWindow& window) {
    if (data.empty()) return;

    const float boxWidth = 50.0f;
    const float boxHeight = 30.0f;
    const float horizontalSpacing = 60.0f;

    for (size_t i = 0; i < data.size(); ++i) {
        float xPos = 100 + i * (boxWidth + horizontalSpacing);
        float yPos = window.getSize().y / 2.0f;

        // Draw the rectangle for the queue element
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setFillColor(sf::Color::Green);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setPosition(xPos, yPos);
        window.draw(box);

        // Draw the value inside the rectangle
        sf::Text valueText;
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Error loading font for queue visualization.\n";
            return;
        }

        valueText.setFont(font);
        valueText.setString(std::to_string(data[i]));
        valueText.setCharacterSize(16);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(xPos + boxWidth / 4, yPos + boxHeight / 4);
        window.draw(valueText);
    }
}
