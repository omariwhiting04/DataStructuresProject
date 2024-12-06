#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Heap.h"
#include "BST.h" // Include the BST header
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

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
    BST bst; 
    Stack stack; 
    Queue queue;
    PriorityQueue priorityQueue; 

    void moveUp();
    void moveDown();
    void selectOption();

    void visualizeHeap();
    void visualizeBST(); 
    void visualizeStack();
    void visualizeQueue();
    void visualizePriorityQueue();

};

#endif
