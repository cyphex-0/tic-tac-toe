#include "Game.h"
#include <iostream>

Game::Game() 
    : window(sf::VideoMode(300, 300), "Tic Tac Toe"), 
      currentPlayer(1), 
      gameWon(false) {
    board.fill({0, 0, 0});
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !gameWon) {
            handleMouseClick(event.mouseButton.x, event.mouseButton.y);
        }
    }
}

void Game::update() {
    // Check for win condition
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            gameWon = true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            gameWon = true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        gameWon = true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        gameWon = true;
    }
}

void Game::render() {
    window.clear(sf::Color::White);

    // Draw the grid
    for (int i = 1; i < 3; ++i) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i * 100, 0), sf::Color::Black),
            sf::Vertex(sf::Vector2f(i * 100, 300), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        
        line[0] = sf::Vertex(sf::Vector2f(0, i * 100), sf::Color::Black);
        line[1] = sf::Vertex(sf::Vector2f(300, i * 100), sf::Color::Black);
        window.draw(line, 2, sf::Lines);
    }

    // Draw X and O
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 1) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(j * 100 + 10, i * 100 + 10), sf::Color::Red),
                    sf::Vertex(sf::Vector2f(j * 100 + 90, i * 100 + 90), sf::Color::Red)
                };
                window.draw(line, 2, sf::Lines);

                line[0] = sf::Vertex(sf::Vector2f(j * 100 + 90, i * 100 + 10), sf::Color::Red);
                line[1] = sf::Vertex(sf::Vector2f(j * 100 + 10, i * 100 + 90), sf::Color::Red);
                window.draw(line, 2, sf::Lines);
            } else if (board[i][j] == 2) {
                sf::CircleShape circle(40);
                circle.setPosition(j * 100 + 10, i * 100 + 10);
                circle.setOutlineColor(sf::Color::Blue);
                circle.setFillColor(sf::Color::Transparent);
                circle.setOutlineThickness(5);
                window.draw(circle);
            }
        }
    }

    window.display();
}

void Game::handleMouseClick(int x, int y) {
    int row = y / 100;
    int col = x / 100;
    if (board[row][col] == 0) {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

void Game::reset() {
    board.fill({0, 0, 0});
    currentPlayer = 1;
    gameWon = false;
}
