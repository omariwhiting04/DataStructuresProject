#ifndef STACK_H
#define STACK_H

#include <vector>
#include <SFML/Graphics.hpp>

class Stack {
private:
    std::vector<int> data; // The stack container
    void drawStack(sf::RenderWindow& window); // Private method for visualization

public:
    Stack(); // Constructor
    void push(int value); // Push a value onto the stack
    void pop(); // Pop a value from the stack
    void visualize(sf::RenderWindow& window); // Visualize the stack
};

#endif
