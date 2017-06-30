#ifndef BOARD_H
#define BOARD_H
#pragma once

#include <iostream>
#include <iomanip>
using namespace std;


class Board
{
public:
    Board();
    void printBoard();
    const int size = 10;
    int board[10][10] = { };

    const int emptyCell = 0;
    const int shipCell = 1;
    const int waterShipCell = 5;
    const int missedShot = 2;
    const int trueShot = 3;
    const int nearTrueShot = 4;
    const int botShipCell = 7;

    friend void placeShips();

};

#endif // BOARD_H
