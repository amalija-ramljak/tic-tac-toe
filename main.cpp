#include <iostream>
#include "TicTacToeGrid.h"


int main() {

    std::cout << "Welcome to a simple Tic Tac Toe." << std::endl;

    std::cout << "Rules:" << std::endl << "To beat the game, a player has to have 3 consecutive marks," << std::endl
                                        << "either diagonally, horizontally or vertically. Play by" << std::endl
                                        << "entering coordinates x and y, both [1, 3]." << std::endl
                                        << "Player X starts first." << std::endl;

    TicTacToeGrid grid(3);
    int x, y;
    grid.statusPrint();
    while(!grid.isDone()) {
        std::cout << std::endl << "Player " << (grid.isPlayerX() ? "X" : "O") << "'s move: ";
        std::cin >> x >> y;
        grid.move(x - 1, y - 1);
    }

    return 0;
}