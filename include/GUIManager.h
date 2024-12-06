#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Heap.h"
#include "BST.h" 
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "RedBlackTree.h"
#include "BTree.h"

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
    RedBlackTree redBlackTree;
    BTree bTree;

    void moveUp();
    void moveDown();
    void selectOption();

    void visualizeHeap();
    void visualizeBST(); 
    void visualizeStack();
    void visualizeQueue();
    void visualizePriorityQueue();
    void visualizeRedBlackTree();
    void visualizeBTree();

};

#endif
