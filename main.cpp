#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Gameboard.h"
#include "Tile.h"

using namespace std;

int main() {

    srand(time(0));
    rand();

    ifstream leaderboard("leaderboard.txt");
    if ( leaderboard.fail() ) {
        cerr << "Error opening leaderboard file";
        return -1;
    }

    vector<string> usernames;
    vector<int> highScores;
    string userName;
    int highScore;
    while (!leaderboard.eof()) {
        leaderboard >> userName;
        leaderboard >> highScore;
        usernames.push_back(userName);
        highScores.push_back(highScore);
    }
    leaderboard.close();

    Gameboard gb; // initializes the gameboard gb using default constructor
    gb.displayGame();

    while (!gb.isGameOver()) {
        char userMove;
        cin >> userMove;
        if (userMove == 'A' || userMove == 'a') {
            gb.moveLeft();
        } else if(userMove == 'D' || userMove == 'd') {
            gb.moveRight();
        } else if (userMove == 'W' || userMove == 'w') {
            gb.moveUp();
        } else if (userMove == 'S' || userMove == 's') {
            gb.moveDown();
        }
        gb.newTile();
        gb.displayGame();
    }


    return 0;
}
