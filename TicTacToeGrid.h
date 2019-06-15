#ifndef TICTACTOEGRID_H
#define TICTACTOEGRID_H

#include <iostream>
#include <new>
#include <vector>
#include <algorithm>

class TicTacToeGrid {
public:
    virtual ~TicTacToeGrid();

public:
    TicTacToeGrid(int dimension);
    void move(int x, int y);
    void statusPrint();

    bool isDone() const;
    bool isPlayerX() const;

private:
    int dimension;
    int winMarks;
    int moveCount;
    bool done;
    bool playerX;
    char *grid;
    std::vector<int> xMarks;
    std::vector<int> oMarks;

    bool isWon();
    bool playerWon(std::vector<int> marks);
};


#endif //TICTACTOEGRID_H
