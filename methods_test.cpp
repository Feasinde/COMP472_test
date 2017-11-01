#include <vector>
#include <iostream>
#include "board.h"
#include "ai.h"
#include "game.h"

using namespace std;

const int WIDTH = 9;
const int HEIGHT = 5;

void printMatrix(vector<vector<char> > matrix)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cout << matrix[x][y];
        }
        cout << endl;
    }
}

void fillMatrix(vector<vector<char> >& state){
	for (int i=0; i < WIDTH; i++){
		for (int j=0; j < HEIGHT; j++){
			state[i][j] = 'X';
		}
	}
}
int main(){
	// Declare and resize vector 
	// that hosts the test state
	vector<vector<char> > state;
	vector<vector<vector<char> > > states;

	state.resize(WIDTH);
	for (int i=0; i < WIDTH; i++){
		state[i].resize(HEIGHT);
	}
	
	// Fill matrix with 'X' and set
	// an arbitrary state with three
	// Gs and three Rs
	fillMatrix(state);
	state[0][0] = 'G';
	state[0][1] = 'G';
	state[1][0] = 'G';
	state[0][3] = 'R';
	state[0][4] = 'R';
	state[3][2] = 'R';

	// Create game instance on which
	// the AIPlayer class may act
	Game* game = new Game();
	AIPlayer ai = AIPlayer(game);
	// Print initial state
	printMatrix(state);
	cout << endl;
	
	////////////////////
	// METHOD TESTING //
	////////////////////

	// getFrontierStates
	states = ai.getFrontierStates(state);
	cout << endl;

	for (auto st : states){
		cout << "This is a state: " << endl;
		printMatrix(st);
		cout << endl;
	}

	// heuristicFunction
	cout << "The heuristic value of the initial state is: ";
	cout << ai.heuristicFunction(state) << endl;
	cout << "The heuristic value of each of the states is: " << endl;
	for (auto st : states){
		cout << ai.heuristicFunction(st) << endl;
	}
	cout << endl;

	//getHeuristic
	cout << "The heuristic of the initial state with level 1 look-ahead is: ";
	cout << ai.getHeuristic(state,1) << endl;
	cout << "The heuristic of the initial state with level 2 look-ahead is: ";
	cout << ai.getHeuristic(state,2) << endl;
	cout << "The heuristic of the initial state with level 3 look-ahead is: ";
	cout << ai.getHeuristic(state,3) << endl;
	cout << "The heuristic of the initial state with level 4 look-ahead is: ";
	cout << ai.getHeuristic(state,4) << endl;
	delete game;
}	