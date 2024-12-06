#include <SFML/Graphics.hpp>
#include "GUIManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Structures Visualization");
    GUIManager guiManager(window);

    while (window.isOpen()) {
        guiManager.handleEvents();
        guiManager.render();
    }

    return 0;
}
