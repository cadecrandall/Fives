//
// Created by Cade Crandall on 8/8/20.
//

#ifndef FIVES_LEADERBOARD_H
#define FIVES_LEADERBOARD_H

#include <unordered_map>
#include <string>

class Leaderboard {
public:
    Leaderboard();

    Leaderboard(std::string file);

    std::pair<std::string, int> getHighScore();

    int addPlayer(int);

    int readLeaderboard();

private:
    std::unordered_map<std::string, int> _leaderboard;

    std::string _filepath;
};


#endif //FIVES_LEADERBOARD_H
