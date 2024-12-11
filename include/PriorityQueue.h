#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <utility> // For std::pair

class PriorityQueue {
private:
    std::vector<std::pair<int, int>> data; // Pair of <priority, value>
    void drawPriorityQueue(sf::RenderWindow& window); // Private method for visualization

public:
    PriorityQueue(); // Constructor
    void enqueue(int value, int priority); // Add a value with priority
    void dequeue(); // Remove the highest-priority value
    void visualize(sf::RenderWindow& window); // Visualize the priority queue
};

#endif
