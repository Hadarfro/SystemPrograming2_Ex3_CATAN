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

using namespace std;

class Catan {
    private:
        const Board& board;
        vector<Player&> players;
        string currentPlayer;
        int numPlayers;

    public:
        Catan(Player p1,Player p2,Player p3 = Player(),Player p4 = Player(),const Board& board = Board()); //initializer list
        void ChooseStartingPlayer();
        const Board& getBoard();
        void printWinner();
        void printGameState() const;
        void takeCards(int roll);
};
