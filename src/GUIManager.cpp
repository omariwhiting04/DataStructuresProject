#include "GUIManager.h"
#include <iostream>

GUIManager::GUIManager(sf::RenderWindow& window)
    : window(window), selectedMenuItemIndex(0), heap(), bst(), stack(), queue(), priorityQueue(), redBlackTree(), bTree(3)  {  
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font. Make sure 'arial.ttf' is in the correct folder.\n";
    }

    // Define menu options
   menuOptions = {"Heap", "BST", "Stack", "Queue", "Priority Queue", "Red-Black Tree", "B-Tree", "Exit"};
    float spacing = 60;
    float verticalOffset = 100;

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
    } else if (menuOptions[selectedMenuItemIndex] == "Stack") {
        std::cout << "Stack selected! Visualizing stack...\n";
        visualizeStack();
    } else if (menuOptions[selectedMenuItemIndex] == "Queue") {
        std::cout << "Queue selected! Visualizing queue...\n";
        visualizeQueue();
    } else if (menuOptions[selectedMenuItemIndex] == "Priority Queue") { 
        std::cout << "Priority Queue selected! Visualizing priority queue...\n";
        visualizePriorityQueue();
    } else if (menuOptions[selectedMenuItemIndex] == "Red-Black Tree") { 
        std::cout << "Red-Black Tree selected! Visualizing Red-Black Tree...\n";
        visualizeRedBlackTree();
       
    } else if (menuOptions[selectedMenuItemIndex] == "B-Tree") { 
        std::cout << "BTree selected! Visualizing BTree...\n";
        visualizeBTree();

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

void GUIManager::visualizeStack() {
    stack.push(10); // Example data
    stack.push(20);
    stack.push(30);
    stack.visualize(window);

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

void GUIManager::visualizeQueue() {
    queue.enqueue(10); // Example data
    queue.enqueue(20);
    queue.enqueue(30);
    queue.visualize(window);

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

void GUIManager::visualizePriorityQueue() {
    priorityQueue.enqueue(15, 3); // Example data
    priorityQueue.enqueue(10, 1);
    priorityQueue.enqueue(20, 2);
    priorityQueue.visualize(window);

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

void GUIManager::visualizeRedBlackTree() {
    std::cout << "Red-Black Tree selected! Visualizing Red-Black Tree...\n";
    redBlackTree.insert(30); // Example data
    redBlackTree.insert(10);
    redBlackTree.insert(50);
    redBlackTree.visualize(window);

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

void GUIManager::visualizeBTree() {
    std::cout << "B-Tree selected! Visualizing B-Tree...\n";

    window.clear(sf::Color::Black);

    bTree.insert(10);
    bTree.insert(20);
    bTree.insert(30);
    bTree.insert(40);

    bTree.visualize(window);

    window.display();

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
