#ifndef SHIP_H
#define SHIP_H
#pragma once

struct ShipsPosition
{
    int x_coord = 0;
    int y_coord = 0;
    int size = 0;
    int maxShipSize = 4;
    int countSubmarine = 4;
    int countDestroyer = 3;
    int countCruisers = 2;
    int countBattleship = 1;

};

#endif // SHIP_H
