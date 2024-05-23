#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "board.hpp"
#include "player.hpp"

class Catan {
    public:
        Board board;
        vector<Player> players;
        int currentPlayer;
        Catan(Player p1,Player p2){//check if needed init the players that dont play!!!!!!!!! 
            players[1] = p1;
            players[2] = p2;
        }
        Catan(Player p1,Player p2,Player p3){
            players[1] = p1;
            players[2] = p2;
            players[3] = p3;
        }
        Catan(Player p1,Player p2,Player p3,Player p4){
            players[1] = p1;
            players[2] = p2;
            players[3] = p3;
            players[4] = p4;
        }

    void printGameState() const {
        std::cout << "Current player: " << players[currentPlayer].name << "\n";
        board.printBoard();
        for (const auto& player : players) {
            player.printResources();
        }
    }

    void ChooseStartingPlayer(){
        // Generate a random number between 1 and 3
        size_t i = rand() % 3 + 1;
        cout << players[i].name << endl;
    }

    Board getBoard(){
        return board;
    }

    void printWinner(){

    }
};
