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

    ifstream leaderboard("leaderboard.txt");
    if (leaderboard.fail()) {
        cerr << "Error opening leaderboard file";
        return -1;
    }

    // reads in the leaderboard file
    vector<int> highScores;
    vector<string> usernames;
    string username;
    int userScore;
    while (!leaderboard.eof()) {
        leaderboard >> username;
        leaderboard >> userScore;
        usernames.push_back(username);
        highScores.push_back(userScore);
    }
    leaderboard.close();

    int bestScore = getBestScore(highScores);

    Gameboard gb; // initializes the gameboard gb using default constructor
    char move;
    while (!gb.isGameOver()) {
        cin >> move;
        makePlayerMove(gb, move);
        gb.printGame();
    }

    cout << "What is your username for the leaderboard?" << endl;
    string currentUserName;
    getline(cin, currentUserName);

    ofstream fout("leaderboard.txt", ios_base::app);
    if (fout.fail()) {
        cerr << "Error opening leaderboard file";
        return -1;
    }

    fout << currentUserName << ' ' << gb.getScore() << endl;
    fout.close();

    return 0;
}