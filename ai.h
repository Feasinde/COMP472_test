#ifndef AI_H
#define AI_H

#include "board.h"
#include "game.h"
#include <vector>

using namespace std;

class AIPlayer{
private:
    Game* game; //Refers to the current game

public:
    AIPlayer(Game* current_game);

    // return a vector of matrices representing all
    // the possible states that the AI can choose
    vector<vector<vector<char>>> getFrontierStates(vector<vector<char> > state);

    // return heuristic associated to a given state
    int heuristicFunction(vector<vector<char>> state);

    // recursively calculate the heuristic value
    // of a minimax node and return the minmax
    // value at the leaves
    int getHeuristic(vector<vector<char> > state, int level);
};

#endif // AI_H

