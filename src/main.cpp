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
    Leaderboard leaderboard;

    leaderboard.readLeaderboard();

    char move;
    while (!gb.isGameOver()) {
        cin >> move;
        makePlayerMove(gb, move);
        gb.printGameState();
    }

    leaderboard.addPlayer(gb.getScore());

    return 0;
}