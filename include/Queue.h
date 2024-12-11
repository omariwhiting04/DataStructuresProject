#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Queue {
private:
    std::vector<int> data; // The queue container
    void drawQueue(sf::RenderWindow& window); // Private method for visualization

public:
    Queue(); // Constructor
    void enqueue(int value); // Add a value to the queue
    void dequeue(); // Remove a value from the queue
    void visualize(sf::RenderWindow& window); // Visualize the queue
};

#endif
