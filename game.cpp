#include "game.h"

int Game::defensiveMoveCtr = 0;
int Game::offensiveMoveCtr = 0;
int Game::moveCtr = 0;
int Game::p1Tokens = 22;
int Game::p2Tokens = 22;

Game::Game()
{
    board = new Board();
    p1Tokens = 22;
    p2Tokens = 22;
    defensiveMoveCtr = 0;
    offensiveMoveCtr = 0;
    moveCtr = 0;
    turn = true;
    isGameOver = false;
}

Game::~Game() {
    delete board;
    delete AI_board;
}

Board* Game::getBoard() {
    return board;
}

int Game::getPlayerTokens(int player) {
    if (player <= 0)
        return p1Tokens;
    else
        return p2Tokens;
}

int Game::getDefensiveMoveCtr()
{
    return defensiveMoveCtr;
}

int Game::getOffensiveMoveCtr() {
    return offensiveMoveCtr;
}

int Game::getMoveCtr() {
    return moveCtr;
}

bool Game::getTurn() {
    return turn;
}

bool Game::checkGameOver() {
    if (p1Tokens <= 0 || p2Tokens <= 0)
        isGameOver = true;

    return isGameOver;
}

void Game::switchTurn() {
    turn = !turn;
}

void Game::updateDefensiveMoveCtr(int amt) {
    if (amt == 0)
        defensiveMoveCtr = 0;
    else
        defensiveMoveCtr += amt;
}

void Game::updateOffensiveMoveCtr(int amt) {
    if (amt == 0)
        offensiveMoveCtr = 0;
    else
        offensiveMoveCtr += amt;
}

void Game::updateMoveCtr(int amt) {
    moveCtr += amt;
}

void Game::setPlayerTokens(int player, int tokens) {
    if (player <= 0)
        p1Tokens -= tokens;
    else
        p2Tokens -= tokens;
}

bool Game::checkStalemate() {
    if (defensiveMoveCtr >= 10)
        return isGameOver = true;

    return false;
}

void Game::restart() {
    delete board;

    board = new Board();
    p1Tokens = 22;
    p2Tokens = 22;
    offensiveMoveCtr = 0;
    defensiveMoveCtr = 0;
    moveCtr = 0;
    turn = true;
    isGameOver = false;
}
