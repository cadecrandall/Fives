#include <iostream>

using namespace std;

#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Gameboard.h"
#include "Functions.h"

int main() {
    srand(time(0));
    rand();

    Gameboard gb;
    Leaderboard lb;

    lb.readLeaderboard();

    char move;
    while (!gb.isGameOver()) {
        cin >> move;
        makePlayerMove(gb, move);
        gb.printGameState(lb);
    }

    lb.writeGameToBoard(gb.getScore());

    return 0;
}