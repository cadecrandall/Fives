//
// Created by Cade Crandall on 12/3/19.
//

#include "Functions.h"

int determineBestScore(std::vector<int> scores) {
    int bestIdx = 0;
    for (int i = 0; i < scores.size(); i++) {
        bestIdx = (scores.at(i) > scores.at(bestIdx) ? i : bestIdx);
    }
    return bestIdx;
}
