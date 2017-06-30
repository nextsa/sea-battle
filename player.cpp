#include "player.h"
#include <assert.h>
Player::Player()
{

}

bool Player::tryPlaceEmpty(Board& board)
{
    //border ...|
    if ((m_y + m_shipSize) > board.size)
    {
        return false;
    }
    for (int j = m_y; j < m_y + m_shipSize; j++)
    {
        if (board.board[m_x][j] != board.emptyCell)
        {
        return false;
        }
    }


/*
    for (int i = m_x - 1; i < m_x + 2; i++)
    {
        if (i < -1 || i > board.size)
        {
            return false;
        }
        for (int j = m_y - 1; j < m_y + m_shipSize + 1; j++)
        {
            if (j < -1 || j > board.size)
            {
                return false;
            }

            if (board.board[i][j] != board.emptyCell)
            {
//                cout << "tryPlaceEmpty(): i = " << i << " j = " << j << endl;
                return false;
            }

        }
    }
    */
    return true;

}

void Player::placeShip(Board& board)
{
    for (int i = m_x - 1; i < m_x + 2; i++)
    {
        for (int j = m_y - 1; j < m_y + m_shipSize + 1; j++)
        {
            if (i >= 0 && i < board.size && j >= 0 && j < board.size)
            {
                board.board[i][j] = board.waterShipCell;
            }
        }
    }

    for (int i = 0; i < m_shipSize; i++)
    {
        board.board[m_x][m_y + i] = board.shipCell;
    }

}

void Player::countShips()
{
    if ( m_shipSize == 1)
    {
        m_submarine++;
    }
    else if (m_shipSize == 2)
    {
        m_destroyer++;
    }
    else if (m_shipSize == 3)
    {
        m_cruiser++;
    }
    else if (m_shipSize == 4)
    {
        m_battleship++;
    }
    else
    {
        cout << "countShips():/n Error: bad ship type!" << endl;
    }
}

bool Player::tryChoseShip()
{
    ShipsPosition ship;

    if ((m_shipSize == 1) && (m_submarine == ship.countSubmarine))
    {
        return false;
    }
    else if ((m_shipSize == 2) && (m_destroyer == ship.countDestroyer))
    {
        return false;
    }
    else if ((m_shipSize == 3) && (m_cruiser == ship.countCruisers))
    {
        return false;
    }
    else if ((m_shipSize == 4)  && (m_battleship == ship.countBattleship))
    {
        return false;
    }
    else
    {
        return true;
    }

}

void Player::placeShips(Board& board)
{
    ShipsPosition ship;
    while (true)
    {
        m_x = rand() % board.size;
        m_y = rand() % board.size;
        m_shipSize = (rand() % 4) + 1;

        assert((m_x >= 0) && (m_x < board.size));
        assert((m_y >= 0) && (m_y < board.size));
        assert((m_shipSize >= 1) && (m_shipSize <= ship.maxShipSize));


        if ((m_submarine == ship.countSubmarine) && (m_destroyer == ship.countDestroyer) && (m_cruiser == ship.countCruisers) && (m_battleship == ship.countBattleship))
        {        // кончились все корабли
            break;
        }

        if (tryChoseShip() == true)
        {
            if (tryPlaceEmpty(board) == true)
            {
                placeShip(board);

                countShips();
            }
        }
     }
}


void Player::placeBotShips(Board& board)
{
    ShipsPosition ship;
    while (true)
    {
        m_x = rand() % board.size;
        m_y = rand() % board.size;
        m_shipSize = (rand() % 4) + 1;

        assert((m_x >= 0) && (m_x < board.size));
        assert((m_y >= 0) && (m_y < board.size));
        assert((m_shipSize >= 1) && (m_shipSize <= ship.maxShipSize));


        if ((m_submarine == ship.countSubmarine) && (m_destroyer == ship.countDestroyer) && (m_cruiser == ship.countCruisers) && (m_battleship == ship.countBattleship))
        {        // кончились все корабли
            break;
        }

        if (tryChoseShip() == true)
        {
            if (tryPlaceEmpty(board) == true)
            {
                placeBotShip(board);

                countShips();
            }
        }
     }
}




void Player::placeBotShip(Board& board)
{
    for (int i = m_x - 1; i < m_x + 2; i++)
    {
        for (int j = m_y - 1; j < m_y + m_shipSize + 1; j++)
        {
            if (i >= 0 && i < board.size && j >= 0 && j < board.size)
            {
                board.board[i][j] = board.waterShipCell;
            }
        }
    }

    for (int i = 0; i < m_shipSize; i++)
    {
        board.board[m_x][m_y + i] = board.botShipCell;
    }

}




bool Player::doesShipExists(Board& board, int x, int y)
{
    if ((board.board[x - 1][y - 1] == board.shipCell)  || (board.board[x][y] == board.botShipCell))
    {
        return true;
    }
    return false;
}

void Player::makeShot(Board& board)
{
    string input;
    cout << "\n\nTo make shot enter coordinates." << endl;
    cout << "x: ";
    cin >> input;
/*    if (isalpha(input))
    {
        if (input = 'q')
        {
            return a.exec();
        }
    }
*/
    int x = atoi(input.c_str());
    cout << "y: ";
    cin >> input;
    int y = atoi(input.c_str());




    if (doesShipExists(board, x, y) == true)
    {
        board.board[x - 1][y - 1] = board.trueShot;
        makeShot(board);
    }
    else
    {
        board.board[x - 1][y - 1] = board.missedShot;

    }
/*
    for(int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 4; j++)
        {
            if (board.board[i][j] == board.waterShipCell)
            {
                board.board[i][j] = board.nearTrueShot;
             }
         }
     }
*/

}

bool Player::gameOver(Board& board)
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            if (board.board[i][j] != board.shipCell)
            {
                return true;
            }
        }
    }
    return false;
}

void Player::makeBotShot(Board& board)
{
    int x = rand() % board.size;
    int y = rand() % board.size;

    if (doesShipExists(board, x, y) == true)
    {
        board.board[x][y] = board.trueShot;
        makeBotShot(board);
    }
    else
    {
        board.board[x][y] = board.missedShot;
    }

}



