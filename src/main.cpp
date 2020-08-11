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
    cout << leaderboard.getHighScore().first;

    char move;
    while (!gb.isGameOver()) {
        cin >> move;
        makePlayerMove(gb, move);
        gb.printGame();
    }

    leaderboard.addPlayer(gb.getScore());

    return 0;
}