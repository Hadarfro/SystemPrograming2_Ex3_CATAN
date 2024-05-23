#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.hpp"
#include "board.hpp"

using namespace std;

class Catan {
    private:
        Board board;
        vector<Player> players;
        size_t currentPlayer;

    public:
    Catan(Player p1,Player p2);
    Catan(Player p1,Player p2,Player p3);
    Catan(Player p1,Player p2,Player p3,Player p4);

    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
    void Catan::printGameState() const;
    int Catan::rollDice();
};
