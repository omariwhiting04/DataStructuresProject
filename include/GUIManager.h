#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Heap.h"
#include "BST.h" // Include the BST header

class GUIManager {
public:
    GUIManager(sf::RenderWindow& window);
    void handleEvents();
    void render();

private:
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<std::string> menuOptions;
    std::vector<sf::Text> menuItems;
    int selectedMenuItemIndex;

    Heap heap;
    BST bst; // Add BST object

    void moveUp();
    void moveDown();
    void selectOption();

    void visualizeHeap();
    void visualizeBST(); // Add function declaration for visualizing BST
};

#endif
