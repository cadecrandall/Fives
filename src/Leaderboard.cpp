//
// Created by Cade Crandall on 8/8/20.
//

#include "Leaderboard.h"

#include <iostream>
#include <fstream>
#include <functional>


Leaderboard::Leaderboard() {
    _filepath = "leaderboard.txt";
}

Leaderboard::Leaderboard(std::string file) {
    _filepath = file;
}


void Leaderboard::determineHighScore() {
    std::pair<std::string, int> winner = make_pair(
            _leaderboard.begin()->first, _leaderboard.begin()->second);
    for (std::pair<std::string, int> p : _leaderboard) {
        winner = (p.second > winner.second ? p : winner);
    }
    _highScorer = winner;
}

int Leaderboard::readLeaderboard() {
    std::ifstream fin(_filepath);
    if (fin.fail()) {
        std::cerr << "Error opening leaderboard file";
        return -1;
    }

    std::string username;
    int score;
    while (!fin.eof()) {
        fin >> username >> score;
        _leaderboard.insert(make_pair(username, score));
    }
    fin.close();

    determineHighScore();

    return 0;
}

int Leaderboard::addPlayer(int score) {
    std::cout << "What is your username for the leaderboard?" << std::endl;
    std::string currentUserName;
    std::cin >> currentUserName;

    std::ofstream fout("leaderboard.txt", std::ios_base::app);
    if (fout.fail()) {
        std::cerr << "Error opening leaderboard file";
        return -1;
    }

    fout << currentUserName << ' ' << score << std::endl;
    fout.close();

    return 0;
}

int Leaderboard::getHighScore() {
    return _highScorer.second;
}

std::string Leaderboard::getHighScoreName() {
    return _highScorer.first;
}

