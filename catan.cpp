#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "board.hpp"
#include "player.hpp"


Catan::Catan(Player p1,Player p2){//check if needed init the players that dont play!!!!!!!!! 
    players[1] = p1;
    players[2] = p2;
}
Catan::Catan(Player p1,Player p2,Player p3){
    players[1] = p1;
    players[2] = p2;
    players[3] = p3;
}
Catan::Catan(Player p1,Player p2,Player p3,Player p4){
    players[1] = p1;
    players[2] = p2;
    players[3] = p3;
    players[4] = p4;
}

void Catan::printGameState() const {
    cout << "Current player: " << players[currentPlayer].getName() << "\n";
    board.printBoard();
    for (const auto& player : players) {
        player.printResources();
    }
}

void Catan::ChooseStartingPlayer(){
    // Generate a random number between 1 and 3
    size_t i = rand() % 3 + 1;
    cout << players[i].getName() << endl;
}

Board Catan::getBoard(){
    return board;
}

void Catan::printWinner(){

}

int Catan::rollDice(){
    int roll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1); // Rolling two six-sided dice
    std::cout << "Dice roll: " << roll << "\n";

    for (const auto& tile : board.tiles) {
        if (tile.number == roll) {
            for (size_t i = 0;i < 3;i++) {
                players[i].addResource(tile.resource,1); // Simplified resource distribution
            }
        }
    }
    return roll;
}
