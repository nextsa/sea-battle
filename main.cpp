#include <QCoreApplication>
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include "board.h"
#include "player.h"

using namespace std;
/*
void getShotCoord()
{
    string input;

    cout << "\n\nTo make shot enter coordinates." << endl;
    cout << "x: ";
    cin >> input;
    if (isalpha(input))
    {
        if (input = 'q')
        {
            return a.exec();
        }
    }

    int x = atoi(input.c_str());
    cout << "y: ";
    cin >> input;
    int y = atoi(input.c_str());
    cout << "Enter ship's size: ";
    cin >> input;
    int size = atoi(input.c_str());


//    getline(cin, x);
//    getline(cin, y);
//    getline(cin, size);
//    cout << "getShotCoord(): x = " << x << "y = " << y << "sz = " << size;
}
    */


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Board humanBoard;
    Player human;

    Board botBoard;
    Player bot;



    while ((human.gameOver(botBoard) != false) && (bot.gameOver(humanBoard) != false))
    {

        cout << "Your board: \n" << endl;

        srand (time(NULL));
        human.placeShips(humanBoard);
        humanBoard.printBoard();

        cout << endl << endl << "Your enemy's board: \n" << endl;

        srand (time(NULL) + 1);
        bot.placeBotShips(botBoard);
        botBoard.printBoard();

//        getShotCoord();




        bot.makeBotShot(humanBoard);
//        system("pause");

        human.makeShot(botBoard);

        system("cls");
    }



    return a.exec();
}
