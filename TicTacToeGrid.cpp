//
// Created by VERA on 24/02/2018.
//

#include "TicTacToeGrid.h"


TicTacToeGrid::TicTacToeGrid(int dimension) {
    this->dimension = dimension;
    winMarks = dimension;
    moveCount = 0;
    done = false;
    grid = new char[dimension*dimension];
    for(int i = 0; i < dimension*dimension; i++) {
        grid[i] = '-';
    }
    playerX = true;
}

TicTacToeGrid::~TicTacToeGrid() {
    delete(grid);
}

void TicTacToeGrid::move(int x, int y) {
    if(grid[dimension*x + y] != '-') {
        std::cout << "Invalid location" << std::endl;
        return;
    }
    moveCount++;
    grid[dimension*x + y] = playerX ? 'x' : 'o';
    playerX ? xMarks.push_back(dimension*x + y) : oMarks.push_back(dimension*x + y);
    done = isWon();

    statusPrint();
    if(moveCount == dimension*dimension) {
        std::cout << "Game is over." << std::endl;
        done = true;
    }
    if(done) {
        std::cout << "Player " << (playerX ? "X" : "O") << " won.";
    }
    playerX = !playerX;
}

bool TicTacToeGrid::isWon() {
    if(xMarks.size() < winMarks && oMarks.size() < winMarks) {
        return false;
    }
    return playerX ? playerWon(xMarks) : playerWon(oMarks);
}

bool TicTacToeGrid::playerWon(std::vector<int> marks) {
    for(int i : marks) {
        int counterV = 1;
        bool vertical = true;
        int counterH = 1;
        bool horizontal = true;
        int counterD = 1;
        bool diagonal = i == 0 || i == dimension - 1 || i == dimension*dimension - 1 || i == (dimension - 1)*dimension;

        while((counterV < dimension && counterH < dimension && counterD < dimension)
                && (horizontal || vertical || diagonal)) {
            int j;
            if(vertical) {
                j = (i + counterV*dimension) % (dimension*dimension);
                if(std::find(marks.begin(), marks.end(), j) != marks.end())
                    counterV++;
                else
                    vertical = false;
            }

            if(horizontal) {
                j = (i + counterH) % (dimension*dimension);
                if(std::find(marks.begin(), marks.end(), j) != marks.end())
                    counterH++;
                else
                    horizontal = false;
            }

            if(diagonal) {
                j = (i + counterD*dimension + counterD) % (dimension*dimension);
                if(std::find(marks.begin(), marks.end(), j) != marks.end())
                    counterD++;
                else
                    diagonal = false;
            }
        }

        if(vertical || horizontal || diagonal) {
            return true;
        }
    }

    return false;
}

void TicTacToeGrid::statusPrint() {
    std::cout << std::endl;
    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension - 1; j++) {
            std::cout << " " << this->grid[this->dimension*i + j] << " |";
        }
        std::cout << " " << this->grid[this->dimension*i + this->dimension - 1] << " " << std::endl;
        if(i < this->dimension - 1) {
            for(int i = 0; i < dimension; i++) {
                std::cout << "---";
                if(i < dimension - 1)
                    std::cout << "-";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

bool TicTacToeGrid::isDone() const {
    return done;
}

bool TicTacToeGrid::isPlayerX() const {
    return playerX;
}
