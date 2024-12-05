#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

class GUIManager {
public:
    // Constructor
    GUIManager();

    // Run the main GUI loop
    void run();

private:
    sf::RenderWindow window;

    // Helper methods
    void handleEvents();
    void render();
};

#endif // GUIMANAGER_H
