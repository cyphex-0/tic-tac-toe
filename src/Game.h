#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <array>

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleMouseClick(int x, int y);
    void reset();

    sf::RenderWindow window;
    std::array<std::array<int, 3>, 3> board; // 0: empty, 1: X, 2: O
    int currentPlayer;
    bool gameWon;
};

#endif // GAME_H
