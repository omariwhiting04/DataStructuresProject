#include "GUIManager.h"
#include <iostream>

GUIManager::GUIManager() 
    : window(sf::VideoMode(800, 600), "Data Structures Visualization") {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
    }
    setupGUI();
}

void GUIManager::setupGUI() {
    // Title
    title.setFont(font);
    title.setString("Data Structures Visualization");
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::White);
    title.setPosition(200, 50);

    // Menu items
    std::vector<std::string> items = {
        "1. Binary Search Tree",
        "2. AVL Tree",
        "3. Red-Black Tree",
        "4. Heap",
        "5. Priority Queue"
    };
    float yPos = 150;
    for (const auto& item : items) {
        sf::Text text;
        text.setFont(font);
        text.setString(item);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Cyan);
        text.setPosition(250, yPos);
        menuItems.push_back(text);
        yPos += 50;
    }
}

void GUIManager::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void GUIManager::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GUIManager::render() {
    window.clear(sf::Color::Black);

    // Draw GUI elements
    window.draw(title);
    for (const auto& item : menuItems) {
        window.draw(item);
    }

    window.display();
}
