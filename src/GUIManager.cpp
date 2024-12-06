#include "GUIManager.h"
#include <iostream>

GUIManager::GUIManager(sf::RenderWindow& window)
    : window(window), selectedMenuItemIndex(0), heap(), bst() { // Initialize both heap and bst
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font. Make sure 'arial.ttf' is in the correct folder.\n";
    }

    // Define menu options
    menuOptions = {"Heap", "BST", "Exit"};
    float verticalOffset = 100;
    float spacing = 60;

    for (size_t i = 0; i < menuOptions.size(); ++i) {
        sf::Text menuItem;
        menuItem.setFont(font);
        menuItem.setString(menuOptions[i]);
        menuItem.setCharacterSize(30);
        menuItem.setFillColor(sf::Color::White);
        menuItem.setPosition(300, verticalOffset + i * spacing);
        menuItems.push_back(menuItem);
    }

    // Highlight the first menu item
    menuItems[selectedMenuItemIndex].setFillColor(sf::Color::Red);
}

void GUIManager::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                moveUp();
            } else if (event.key.code == sf::Keyboard::Down) {
                moveDown();
            } else if (event.key.code == sf::Keyboard::Enter) {
                selectOption();
            }
        }
    }
}

void GUIManager::render() {
    window.clear();
    for (auto& menuItem : menuItems) {
        window.draw(menuItem);
    }
    window.display();
}

void GUIManager::moveUp() {
    if (selectedMenuItemIndex - 1 >= 0) {
        menuItems[selectedMenuItemIndex].setFillColor(sf::Color::White);
        selectedMenuItemIndex--;
        menuItems[selectedMenuItemIndex].setFillColor(sf::Color::Red);
    }
}

void GUIManager::moveDown() {
    if (selectedMenuItemIndex + 1 < menuItems.size()) {
        menuItems[selectedMenuItemIndex].setFillColor(sf::Color::White);
        selectedMenuItemIndex++;
        menuItems[selectedMenuItemIndex].setFillColor(sf::Color::Red);
    }
}

void GUIManager::selectOption() {
    if (menuOptions[selectedMenuItemIndex] == "Heap") {
        std::cout << "Heap selected! Visualizing heap...\n";
        visualizeHeap();
    } else if (menuOptions[selectedMenuItemIndex] == "BST") {
        std::cout << "BST selected! Visualizing BST...\n";
        visualizeBST();
    } else if (menuOptions[selectedMenuItemIndex] == "Exit") {
        window.close();
    }
}

void GUIManager::visualizeHeap() {
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.visualize(window);

    // Wait for the user to close or go back
    sf::Event event;
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            std::cout << "Returning to menu.\n";
            break;
        }
    }
}

void GUIManager::visualizeBST() {
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.visualize(window);

    // Wait for the user to close or go back
    sf::Event event;
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            std::cout << "Returning to menu.\n";
            break;
        }
    }
}
