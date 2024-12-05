#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class GUIManager {
public:
    GUIManager();
    void run();

private:
    sf::RenderWindow window;

    // GUI elements
    sf::Font font;
    sf::Text title;
    std::vector<sf::Text> menuItems;

    // Helper methods
    void setupGUI();
    void handleEvents();
    void render();
};

#endif // GUIMANAGER_H
