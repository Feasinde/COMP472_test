#include "ai.h"
#include "board.h"
#include "game.h"
#include <vector>

using namespace std;

AIPlayer::AIPlayer(Game *current_game) : game(current_game)
{}

vector<vector<vector<char>>> AIPlayer::getFrontierStates(vector<vector<char> > state){

    vector<vector<vector<char>>> possible_states = {};
    
    // iterate across the matrix to find all Red tokens and
    // calculate frontier states depending on the available
    // moves of each token
    for (int i=0; i < game->getBoard()->getWidth(); i++){
        for(int j=0; j < game->getBoard()->getHeight(); j++){
            if (state[i][j] == 'R'){
                
                // temporary board object where we perform
                // move checking and attacks in order to retrieve
                // frontier states
                Board* temporary_board = new Board(state);

                vector<vector<int> > valid_adjancent_tiles = temporary_board->getEmptyAdjacentValidTiles(i,j);
                if (valid_adjancent_tiles.size() != 0){

                    //iterate over all valid adjacent tiles
                    for (auto valid_move : valid_adjancent_tiles) {

                        if (temporary_board->checkMove(i,j,valid_move[0],valid_move[1])){
                            temporary_board->performAttack(i,j,valid_move[0],valid_move[1]);

                            // if an attack is performed, the resulting matrix is stored
                            // in the frontier states
                            possible_states.push_back(temporary_board->getMatrix());

                            // in order to proceed with the rest of the valid adjacent
                            // tiles, the temporary board must be reset to the current
                            // state
                            delete temporary_board;
                            temporary_board = new Board(state);
                        }

                    }
                }
                delete temporary_board;
            }
        }
    }
    return possible_states;
}

int AIPlayer::heuristicFunction(vector<vector<char> > state){
    // naive heuristic function described in
    // the project section of the moodle page
    const int WIDTH = game->getBoard()->getWidth();
    const int HEIGHT = game->getBoard()->getHeight();

    int h_green_sum=0, h_red_sum=0, v_green_sum=0, v_red_sum=0;

    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            if (state[x][y] == 'G'){
                h_green_sum += x;
                v_green_sum += y;
            }
            else if (state[x][y] == 'R'){
                h_red_sum += x;
                v_red_sum += y;
            }
        }
    }
    return 100*v_green_sum+50*h_green_sum-100*v_red_sum-50*h_red_sum;
}

int AIPlayer::getHeuristic(vector<vector<char> > state, int level){
    // determine whether function is called at
    // a min or max node. INITIAL CALL IS ALWAYS
    // PERFORMED AT A MAX NODE
    bool min_level = level % 2 == 0 ? false : true;


    // if level is zero, then return the heuristic
    // value given by the heuristic function
    if (level == 0){
        return heuristicFunction(state);
    }

    //if level is not zero, recursively call
    // getHeuristic() on all frontier states
    else {
        vector<vector<vector<char> > > current_level_states = getFrontierStates(state);

        // call getHeuristic on first element of frontier states
        // to perform the initial comparison
        int return_heuristic = getHeuristic(current_level_states[0], level-1);

        // compare each state and determine greatest or
        // smallest heuristic depending on whether level
        // is min or max
        for (auto state : current_level_states){
            int current_state_heuristic = getHeuristic(state, level-1);
            if (min_level){
                return_heuristic = return_heuristic > current_state_heuristic ? return_heuristic : current_state_heuristic;
            }
            else {
                return_heuristic = return_heuristic < current_state_heuristic ? current_state_heuristic : return_heuristic;
            }
        }
        return return_heuristic;
    }
}
