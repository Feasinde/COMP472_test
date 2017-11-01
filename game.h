#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
private:
    Board* board;
    Board* AI_board;
    static int p1Tokens;
    static int p2Tokens;
    bool turn;
    bool isGameOver;
    static int defensiveMoveCtr;
    static int offensiveMoveCtr;
    static int moveCtr;

public:
    Game();
    ~Game();
    Board *getBoard();
    int getPlayerTokens(int player);
    int getDefensiveMoveCtr();
    int getOffensiveMoveCtr();
    int getMoveCtr();
    bool getTurn();
    bool checkGameOver();
    void switchTurn();
    static void setPlayerTokens(int player, int tokens);
    static void updateDefensiveMoveCtr(int amt);
    static void updateOffensiveMoveCtr(int amt);
    static void updateMoveCtr(int amt);
    bool checkStalemate();
    void restart();
};

#endif // GAME_H
