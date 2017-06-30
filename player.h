#ifndef BOT_H
#define BOT_H
#include "ship.h"
#include "board.h"
#include <ctime>

class Player
{
public:
    Player();
    void placeShips(Board& board);
    bool tryPlaceEmpty(Board& board);
    void placeShip(Board& board);
    void countShips();
    bool tryChoseShip();
    void makeShot(Board& board);
    bool doesShipExists(Board& board, int x, int y);
    bool gameOver(Board& board);
    void makeBotShot(Board& board);

    void placeBotShips(Board& board);
    void placeBotShip(Board& board);





private:
    int m_x = 0;
    int m_y = 0;
    int m_shipSize = 0;
    int m_submarine = 0;
    int m_destroyer = 0;
    int m_cruiser = 0;
    int m_battleship = 0;
};

#endif // BOT_H
