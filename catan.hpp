/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.hpp"
#include "board.hpp"
#include "cards.hpp"
#include "resource.hpp"

using namespace std;

class Catan {
    private:
        Board* board;
        Player players[4];
        Player* currentPlayer;
        size_t indexOfCurrentP;
        unsigned int numPlayers;

    public:
        Catan(Player p1,Player p2,Player p3 = Player(),Player p4 = Player(),Board* b = nullptr); //initializer list
        void ChooseStartingPlayer();
        Board* getBoard();
        void printWinner();
        void printGameState() const;
        void rollDiceOfCurrentPlayer();
        bool isVertexAvilable(int v);
        void nextPlayer();
        Player* getCurrentPlayer();
        size_t getPlayerByName(string name);
};
