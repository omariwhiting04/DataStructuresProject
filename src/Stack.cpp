#include "Stack.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

Stack::Stack() {}

void Stack::push(int value) {
    data.push_back(value); // Add value to the stack
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back(); // Remove the top value
    } else {
        std::cerr << "Stack is empty. Cannot pop.\n";
    }
}

void Stack::visualize(sf::RenderWindow& window) {
    window.clear();

    const float boxWidth = 50.0f;
    const float boxHeight = 30.0f;
    const float verticalSpacing = 40.0f;

    for (size_t i = 0; i < data.size(); ++i) {
        float xPos = window.getSize().x / 2.0f - boxWidth / 2.0f;
        float yPos = window.getSize().y - (i + 1) * (boxHeight + verticalSpacing);

        // Draw the rectangle for the stack element
        sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
        box.setFillColor(sf::Color::Blue);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setPosition(xPos, yPos);
        window.draw(box);

        // Draw the value inside the rectangle
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Error loading font for stack visualization.\n";
            return;
        }

        sf::Text valueText;
        valueText.setFont(font);
        valueText.setString(std::to_string(data[i]));
        valueText.setCharacterSize(16);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(xPos + boxWidth / 4, yPos + boxHeight / 4);
        window.draw(valueText);
    }

    window.display();
}
