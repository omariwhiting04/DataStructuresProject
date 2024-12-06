#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <SFML/Graphics.hpp>

class Heap {
private:
    std::vector<int> data;
    void drawHeap(sf::RenderWindow& window);

public:
    Heap();
    void insert(int value);
    void remove();
    void visualize(sf::RenderWindow& window);
};

#endif
