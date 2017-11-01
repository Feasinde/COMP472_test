#ifndef BOARD_H
#define BOARD_H

#include <vector>
using namespace std;

class Board
{
private:
    const int WIDTH = 9;
    const int HEIGHT = 5;
    vector<vector<char>> boardMatrix;

public:
    static int defensiveMoveCtr;
    Board();
    Board(vector<vector<char> >);
    int getWidth();
    int getHeight();
    vector<vector<char>> getMatrix();
    char getValueAt(int x, int y);
    bool getTileColor(int x, int y);
    bool checkMove(int x1, int y1, int x2, int y2);
    void performAttack(int x1, int y1, int x2, int y2);
    vector<vector<int>> getEmptyAdjacentValidTiles(int x, int y);
    vector<vector<int>> getEmptyAdjacentInvalidTiles(int x, int y);
    void updateBoard(int x1, int y1, int x2, int y2);
    void printBoard();
    void attack(int x, int y, vector<int> direction, char currentPlayer);

    // Required for the AI player's copy of the board
    void setMatrix(vector<vector<char>> new_matrix);
};

#endif // BOARD_H
