#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.hpp"

using namespace std;



class Catan {
    private:
        Board board;
        vector<Player> players;
        int currentPlayer;

    public:
    Catan(Player p1,Player p2,Player p3){//continue!!!!!!!!!!!!11
        players[1] = p1;
        players[2] = p2;
        players[3] = p3;
    }

    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
};
